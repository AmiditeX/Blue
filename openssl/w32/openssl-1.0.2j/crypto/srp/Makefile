DIR=	srp
TOP=	../..
CC=	cc
INCLUDES= -I.. -I$(TOP) -I../../include
CFLAG=-g
INSTALL_PREFIX=
OPENSSLDIR=     /usr/local/ssl
INSTALLTOP=/usr/local/ssl
MAKE=		make -f Makefile.ssl
MAKEDEPPROG=	makedepend
MAKEDEPEND=	$(TOP)/util/domd $(TOP) -MD $(MAKEDEPPROG)
MAKEFILE=	Makefile.ssl
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile
TEST=srptest.c
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC=srp_lib.c srp_vfy.c
LIBOBJ=srp_lib.o srp_vfy.o

SRC= $(LIBSRC)

EXHEADER= srp.h
HEADER=	$(EXHEADER)

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

srptest: top srptest.c $(LIB)
	$(CC) $(CFLAGS) -Wall -Werror -g -o srptest srptest.c $(LIB)

lint:
	lint -DLINT $(INCLUDES) $(SRC)>fluff

update: depend

depend:
	$(MAKEDEPEND) -- $(CFLAG) $(INCLUDES) $(DEPFLAG) -- $(PROGS) $(LIBSRC)

dclean:
	$(PERL) -pe 'if (/^# DO NOT DELETE THIS LINE/) {print; exit(0);}' $(MAKEFILE) >Makefile.new
	mv -f Makefile.new $(MAKEFILE)

clean:
	rm -f *.o *.obj lib tags core .pure .nfs* *.old *.bak fluff

# DO NOT DELETE THIS LINE -- make depend depends on it.

srp_lib.o: ../../e_os.h ../../include/openssl/asn1.h
srp_lib.o: ../../include/openssl/bio.h ../../include/openssl/bn.h
srp_lib.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
srp_lib.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
srp_lib.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
srp_lib.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
srp_lib.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
srp_lib.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
srp_lib.o: ../../include/openssl/sha.h ../../include/openssl/srp.h
srp_lib.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
srp_lib.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
srp_lib.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
srp_lib.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
srp_lib.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
srp_lib.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
srp_lib.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
srp_lib.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
srp_lib.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
srp_lib.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
srp_lib.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
srp_lib.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
srp_lib.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
srp_lib.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
srp_lib.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
srp_lib.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
srp_lib.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
srp_lib.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
srp_lib.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
srp_lib.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
srp_lib.o: c:\mingw\include\ws2tcpip.h
srp_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
srp_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h srp_grps.h srp_lcl.h
srp_lib.o: srp_lib.c
srp_vfy.o: ../../e_os.h ../../include/openssl/asn1.h
srp_vfy.o: ../../include/openssl/bio.h ../../include/openssl/bn.h
srp_vfy.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
srp_vfy.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
srp_vfy.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
srp_vfy.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
srp_vfy.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
srp_vfy.o: ../../include/openssl/ossl_typ.h ../../include/openssl/rand.h
srp_vfy.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
srp_vfy.o: ../../include/openssl/srp.h ../../include/openssl/stack.h
srp_vfy.o: ../../include/openssl/symhacks.h ../../include/openssl/txt_db.h
srp_vfy.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
srp_vfy.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
srp_vfy.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
srp_vfy.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
srp_vfy.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
srp_vfy.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
srp_vfy.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
srp_vfy.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
srp_vfy.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
srp_vfy.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
srp_vfy.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
srp_vfy.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
srp_vfy.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
srp_vfy.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
srp_vfy.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
srp_vfy.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
srp_vfy.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
srp_vfy.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
srp_vfy.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
srp_vfy.o: c:\mingw\include\ws2tcpip.h
srp_vfy.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
srp_vfy.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h srp_lcl.h srp_vfy.c
