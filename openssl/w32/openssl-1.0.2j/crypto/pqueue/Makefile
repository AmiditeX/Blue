#
# OpenSSL/crypto/pqueue/Makefile
#

DIR=	pqueue
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
LIBSRC=pqueue.c
LIBOBJ=pqueue.o

SRC= $(LIBSRC)

EXHEADER= pqueue.h
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

pqueue.o: ../../e_os.h ../../include/openssl/bio.h ../../include/openssl/bn.h
pqueue.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
pqueue.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
pqueue.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
pqueue.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
pqueue.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
pqueue.o: ../../include/openssl/symhacks.h ../../ms/applink.c ../../ms/uplink.h
pqueue.o: ../cryptlib.h c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
pqueue.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
pqueue.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
pqueue.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
pqueue.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
pqueue.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
pqueue.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
pqueue.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
pqueue.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
pqueue.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
pqueue.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
pqueue.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
pqueue.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
pqueue.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
pqueue.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
pqueue.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
pqueue.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
pqueue.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
pqueue.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pqueue.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pqueue.c pqueue.h
