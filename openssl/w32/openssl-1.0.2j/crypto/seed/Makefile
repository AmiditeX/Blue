#
# crypto/seed/Makefile
#

DIR=	seed
TOP=	../..
CC=	cc
CPP=	$(CC) -E
INCLUDES=
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile
TEST=
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC=seed.c seed_ecb.c seed_cbc.c seed_cfb.c seed_ofb.c
LIBOBJ=seed.o seed_ecb.o seed_cbc.o seed_cfb.o seed_ofb.o

SRC= $(LIBSRC)

EXHEADER= seed.h
HEADER= seed_locl.h $(EXHEADER)

ALL=    $(GENERAL) $(SRC) $(HEADER)

top:
	(cd ../..; $(MAKE) DIRS=crypto SDIRS=$(DIR) sub_all)

all:	lib

lib:	$(LIBOBJ)
	$(AR) $(LIB) $(LIBOBJ)
	$(RANLIB) $(LIB) || echo Never mind.
	@touch lib

files:
	$(PERL) $(TOP)/util/files.pl Makefile >> $(TOP)/MINFO

links:
	@$(PERL) $(TOP)/util/mklink.pl ../../include/openssl $(EXHEADER)
	@$(PERL) $(TOP)/util/mklink.pl ../../test $(TEST)
	@$(PERL) $(TOP)/util/mklink.pl ../../apps $(APPS)

install:
	@[ -n "$(INSTALLTOP)" ] # should be set by top Makefile...
	@headerlist="$(EXHEADER)"; for i in $$headerlist ; \
	do  \
	(cp $$i $(INSTALL_PREFIX)$(INSTALLTOP)/include/openssl/$$i; \
	chmod 644 $(INSTALL_PREFIX)$(INSTALLTOP)/include/openssl/$$i ); \
	done;

tags:
	ctags $(SRC)

tests:

lint:
	lint -DLINT $(INCLUDES) $(SRC)>fluff

update: depend

depend:
	@[ -n "$(MAKEDEPEND)" ] # should be set by upper Makefile...
	$(MAKEDEPEND) -- $(CFLAG) $(INCLUDES) $(DEPFLAG) -- $(PROGS) $(LIBSRC)

dclean:
	$(PERL) -pe 'if (/^# DO NOT DELETE THIS LINE/) {print; exit(0);}' $(MAKEFILE) >Makefile.new
	mv -f Makefile.new $(MAKEFILE)

clean:
	rm -f *.o *.obj lib tags core .pure .nfs* *.old *.bak fluff

# DO NOT DELETE THIS LINE -- make depend depends on it.

seed.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
seed.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
seed.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
seed.o: ../../include/openssl/seed.h ../../include/openssl/stack.h
seed.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
seed.o: c:\mingw\include\memory.h c:\mingw\include\msvcrtver.h
seed.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
seed.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
seed.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
seed.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
seed.o: c:\mingw\include\wchar.h
seed.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
seed.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h seed.c seed_locl.h
seed_cbc.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
seed_cbc.o: ../../include/openssl/modes.h ../../include/openssl/opensslconf.h
seed_cbc.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
seed_cbc.o: ../../include/openssl/safestack.h ../../include/openssl/seed.h
seed_cbc.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
seed_cbc.o: c:\mingw\include\_mingw.h c:\mingw\include\msvcrtver.h
seed_cbc.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
seed_cbc.o: c:\mingw\include\stdlib.h c:\mingw\include\sys/types.h
seed_cbc.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
seed_cbc.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
seed_cbc.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h seed_cbc.c
seed_cfb.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
seed_cfb.o: ../../include/openssl/modes.h ../../include/openssl/opensslconf.h
seed_cfb.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
seed_cfb.o: ../../include/openssl/safestack.h ../../include/openssl/seed.h
seed_cfb.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
seed_cfb.o: c:\mingw\include\_mingw.h c:\mingw\include\msvcrtver.h
seed_cfb.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
seed_cfb.o: c:\mingw\include\stdlib.h c:\mingw\include\sys/types.h
seed_cfb.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
seed_cfb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
seed_cfb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h seed_cfb.c
seed_ecb.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
seed_ecb.o: ../../include/openssl/opensslconf.h
seed_ecb.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
seed_ecb.o: ../../include/openssl/safestack.h ../../include/openssl/seed.h
seed_ecb.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
seed_ecb.o: c:\mingw\include\_mingw.h c:\mingw\include\msvcrtver.h
seed_ecb.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
seed_ecb.o: c:\mingw\include\stdlib.h c:\mingw\include\sys/types.h
seed_ecb.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
seed_ecb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
seed_ecb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h seed_ecb.c
seed_ofb.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
seed_ofb.o: ../../include/openssl/modes.h ../../include/openssl/opensslconf.h
seed_ofb.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
seed_ofb.o: ../../include/openssl/safestack.h ../../include/openssl/seed.h
seed_ofb.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
seed_ofb.o: c:\mingw\include\_mingw.h c:\mingw\include\msvcrtver.h
seed_ofb.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
seed_ofb.o: c:\mingw\include\stdlib.h c:\mingw\include\sys/types.h
seed_ofb.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
seed_ofb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
seed_ofb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h seed_ofb.c
