#
# crypto/ecdh/Makefile
#

DIR=	ecdh
TOP=	../..
CC=	cc
INCLUDES= -I.. -I$(TOP) -I../../include
CFLAG=-g -Wall
MAKEFILE=	Makefile
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile
TEST=ecdhtest.c
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC=	ech_lib.c ech_ossl.c ech_key.c ech_err.c ech_kdf.c

LIBOBJ=	ech_lib.o ech_ossl.o ech_key.o ech_err.o ech_kdf.o

SRC= $(LIBSRC)

EXHEADER= ecdh.h
HEADER=	ech_locl.h $(EXHEADER)

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
	@headerlist="$(EXHEADER)"; for i in $$headerlist; \
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
	rm -f *.o */*.o *.obj lib tags core .pure .nfs* *.old *.bak fluff

# DO NOT DELETE THIS LINE -- make depend depends on it.

ech_err.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ech_err.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
ech_err.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
ech_err.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ech_err.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
ech_err.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
ech_err.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
ech_err.o: c:\mingw\include\_mingw.h c:\mingw\include\errno.h
ech_err.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ech_err.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ech_err.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ech_err.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ech_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ech_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ech_err.c
ech_kdf.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ech_kdf.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
ech_kdf.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
ech_kdf.o: ../../include/openssl/evp.h ../../include/openssl/obj_mac.h
ech_kdf.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
ech_kdf.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ech_kdf.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ech_kdf.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ech_kdf.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ech_kdf.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ech_kdf.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ech_kdf.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ech_kdf.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ech_kdf.o: c:\mingw\include\wchar.h
ech_kdf.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ech_kdf.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ech_kdf.c
ech_key.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ech_key.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
ech_key.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
ech_key.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
ech_key.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
ech_key.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
ech_key.o: c:\mingw\include\_mingw.h c:\mingw\include\msvcrtver.h
ech_key.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
ech_key.o: c:\mingw\include\stdlib.h c:\mingw\include\sys/types.h
ech_key.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
ech_key.o: c:\mingw\include\w32api.h
ech_key.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ech_key.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ech_key.c ech_locl.h
ech_lib.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ech_lib.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
ech_lib.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ech_lib.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
ech_lib.o: ../../include/openssl/engine.h ../../include/openssl/err.h
ech_lib.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
ech_lib.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
ech_lib.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
ech_lib.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pkcs7.h
ech_lib.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
ech_lib.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
ech_lib.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
ech_lib.o: c:\mingw\include\_mingw.h c:\mingw\include\errno.h
ech_lib.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ech_lib.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ech_lib.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ech_lib.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ech_lib.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ech_lib.o: c:\mingw\include\wchar.h
ech_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ech_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ech_lib.c ech_locl.h
ech_ossl.o: ../../e_os.h ../../include/openssl/asn1.h
ech_ossl.o: ../../include/openssl/bio.h ../../include/openssl/bn.h
ech_ossl.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
ech_ossl.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ech_ossl.o: ../../include/openssl/ecdh.h ../../include/openssl/err.h
ech_ossl.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
ech_ossl.o: ../../include/openssl/opensslconf.h
ech_ossl.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ech_ossl.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
ech_ossl.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
ech_ossl.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
ech_ossl.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
ech_ossl.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
ech_ossl.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
ech_ossl.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
ech_ossl.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
ech_ossl.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
ech_ossl.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
ech_ossl.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
ech_ossl.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
ech_ossl.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
ech_ossl.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
ech_ossl.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
ech_ossl.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
ech_ossl.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
ech_ossl.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
ech_ossl.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
ech_ossl.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
ech_ossl.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
ech_ossl.o: c:\mingw\include\ws2tcpip.h
ech_ossl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ech_ossl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ech_locl.h
ech_ossl.o: ech_ossl.c
