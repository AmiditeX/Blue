#
# OpenSSL/crypto/lhash/Makefile
#

DIR=	lhash
TOP=	../..
CC=	cc
INCLUDES=
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile
TEST=
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC=lhash.c lh_stats.c
LIBOBJ=lhash.o lh_stats.o

SRC= $(LIBSRC)

EXHEADER= lhash.h
HEADER=	$(EXHEADER)

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

lh_stats.o: ../../e_os.h ../../include/openssl/bio.h
lh_stats.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
lh_stats.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
lh_stats.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
lh_stats.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
lh_stats.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
lh_stats.o: ../../include/openssl/symhacks.h ../../ms/applink.c
lh_stats.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
lh_stats.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
lh_stats.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
lh_stats.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
lh_stats.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
lh_stats.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
lh_stats.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
lh_stats.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
lh_stats.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
lh_stats.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
lh_stats.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
lh_stats.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
lh_stats.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
lh_stats.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
lh_stats.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
lh_stats.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
lh_stats.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
lh_stats.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
lh_stats.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
lh_stats.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h lh_stats.c
lhash.o: ../../include/openssl/bio.h ../../include/openssl/crypto.h
lhash.o: ../../include/openssl/e_os2.h ../../include/openssl/lhash.h
lhash.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
lhash.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
lhash.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
lhash.o: c:\mingw\include\_mingw.h c:\mingw\include\msvcrtver.h
lhash.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
lhash.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
lhash.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
lhash.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
lhash.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
lhash.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h lhash.c
