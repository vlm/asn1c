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
	char **argv;
	char *envp[] = { NULL };	/* Empty environment */
	int ret;
	int i;

	if(ac < 3) {
		setgid(getgid());
		setuid(getuid());
		fprintf(stderr,
			"Usage: %s <chroot-to> <chdir-to> [options]\n", av[0]);
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

	argv = calloc(ac + 1, sizeof(*argv));
	if(argv) {
		argv[0] = "asn1c";
		argv[1] = "-S/skeletons";
		memcpy(argv + 2, av + 3, (ac - 3) * sizeof(*argv));
	} else {
		perror("malloc()");
		exit(EX_OSERR);
	}

	/*
	 * Check arguments for the permitted alphabet constraints.
	 */
	for(i = 3; i < ac; i++) {
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

	execve("/bin/asn1c", argv, envp);

	exit(EX_UNAVAILABLE);
}

