#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sysexits.h>

/*
 * This program chroots into a given directory,
 * then executes the asn1c command with strict arguments checking.
 */
int
main(int ac, char **av) {
	char cmdPath[32];
	char *envp[] = { NULL };	/* Empty environment */
	int ret;
	int i;

	if(ac < 4) {
		setgid(getgid());
		setuid(getuid());
		fprintf(stderr,
		"Usage: %s <chroot-to> <chdir-to> <command> [options]\n",
		av[0]);
		exit(EX_USAGE);
	}

	ret = chroot(av[1]);

	/* Drop the privileges */
	setgid(getgid());
	setuid(getuid());

	if(ret != 0) {
		fprintf(stderr, "chroot(\"%s\") failed: %s\n",
			av[1], strerror(errno));
		exit(EX_OSERR);
	}

	if(chdir(av[2]) != 0) {
		fprintf(stderr, "chdir(\"%s\") failed: %s\n",
			av[2], strerror(errno));
		exit(EX_OSERR);
	}

	if(ac > 64) {
		fprintf(stderr, "Insecure number of arguments: %d\n", ac);
		exit(EX_DATAERR);
	}


	/*
	 * Add an argument if this is an asn1c compiler.
	 */
	if(strcmp(av[3], "asn1c") == 0) {
		ac -= 2;
		av += 2;
		av[0] = "asn1c";
		av[1] = "-S/skeletons";
		i = 2;
		strcpy(cmdPath, "/bin/asn1c");
	} else {
		ac -= 3;
		av += 3;
		i = 0;
	}

	if(strlen(av[0]) > sizeof(cmdPath)/2) {
		fprintf(stderr, "Insecure command name: %s\n", av[0]);
		exit(EX_DATAERR);
	}
	memcpy(cmdPath, "/bin/", 5);
	strcpy(cmdPath + 5, av[0]);

	/*
	 * Check arguments for the permitted alphabet constraints.
	 */
	for(; i < ac; i++) {
		char *p;
		for(p = av[i];; p++) {
			switch(*p) {
			case '0' ... '9': case 'A' ... 'Z': case 'a' ... 'z':
			case '.': case '_': case '-': case '=':
				continue;
			case '\0':
			default:
				break;
			}
			break;
		}
		if(*p || (p - av[i]) > 250) {
			fprintf(stderr, "Insecure argument %d\n", i);
			exit(EX_DATAERR);
		}
	}

	execve(cmdPath, av, envp);
	perror(cmdPath);

	exit(EX_UNAVAILABLE);
}

