
all:
	@for xbr in *.xbr; do					\
		ber=`echo "$$xbr" | sed -e 's/\.xbr$$/\.ber/'`;	\
		if [ $$xbr -nt $$ber ]; then			\
			echo "../../enber $$xbr > $$ber";	\
			../../enber $$xbr > $$ber || exit $$?;	\
		fi;						\
	done
