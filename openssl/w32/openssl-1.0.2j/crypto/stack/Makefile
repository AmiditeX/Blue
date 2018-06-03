#
# OpenSSL/crypto/stack/Makefile
#

DIR=	stack
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
LIBSRC=stack.c
LIBOBJ=stack.o

SRC= $(LIBSRC)

EXHEADER= stack.h safestack.h
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

stack.o: ../../e_os.h ../../include/openssl/asn1.h ../../include/openssl/bio.h
stack.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
stack.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
stack.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
stack.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
stack.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
stack.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
stack.o: ../../include/openssl/symhacks.h ../../ms/applink.c ../../ms/uplink.h
stack.o: ../cryptlib.h c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
stack.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
stack.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
stack.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
stack.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
stack.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
stack.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
stack.o: c:\mingw\include\string.h c:\mingw\include\strings.h
stack.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
stack.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
stack.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
stack.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
stack.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
stack.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
stack.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
stack.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
stack.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
stack.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
stack.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
stack.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h stack.c
