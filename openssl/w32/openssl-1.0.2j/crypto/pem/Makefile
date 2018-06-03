#
# OpenSSL/crypto/pem/Makefile
#

DIR=	pem
TOP=	../..
CC=	cc
INCLUDES= -I.. -I$(TOP) -I../../include
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile
TEST=
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC= pem_sign.c pem_seal.c pem_info.c pem_lib.c pem_all.c pem_err.c \
	pem_x509.c pem_xaux.c pem_oth.c pem_pk8.c pem_pkey.c pvkfmt.c

LIBOBJ=	pem_sign.o pem_seal.o pem_info.o pem_lib.o pem_all.o pem_err.o \
	pem_x509.o pem_xaux.o pem_oth.o pem_pk8.o pem_pkey.o pvkfmt.o

SRC= $(LIBSRC)

EXHEADER= pem.h pem2.h
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

links: $(EXHEADER)
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
	$(MAKEDEPEND) -- $(CFLAG) $(INCLUDES) $(DEPFLAG) -- $(LIBSRC)

dclean:
	$(PERL) -pe 'if (/^# DO NOT DELETE THIS LINE/) {print; exit(0);}' $(MAKEFILE) >Makefile.new
	mv -f Makefile.new $(MAKEFILE)

clean:
	rm -f *.o *.obj lib tags core .pure .nfs* *.old *.bak fluff

# DO NOT DELETE THIS LINE -- make depend depends on it.

pem_all.o: ../../e_os.h ../../include/openssl/asn1.h
pem_all.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
pem_all.o: ../../include/openssl/crypto.h ../../include/openssl/dh.h
pem_all.o: ../../include/openssl/dsa.h ../../include/openssl/e_os2.h
pem_all.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
pem_all.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
pem_all.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
pem_all.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
pem_all.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
pem_all.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pem.h
pem_all.o: ../../include/openssl/pem2.h ../../include/openssl/pkcs7.h
pem_all.o: ../../include/openssl/rsa.h ../../include/openssl/safestack.h
pem_all.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
pem_all.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
pem_all.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
pem_all.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
pem_all.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
pem_all.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
pem_all.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
pem_all.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
pem_all.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
pem_all.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
pem_all.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
pem_all.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
pem_all.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
pem_all.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
pem_all.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
pem_all.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
pem_all.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
pem_all.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
pem_all.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
pem_all.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
pem_all.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
pem_all.o: c:\mingw\include\ws2tcpip.h
pem_all.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pem_all.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pem_all.c
pem_err.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
pem_err.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
pem_err.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
pem_err.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
pem_err.o: ../../include/openssl/err.h ../../include/openssl/evp.h
pem_err.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
pem_err.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
pem_err.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
pem_err.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
pem_err.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
pem_err.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
pem_err.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
pem_err.o: ../../include/openssl/x509_vfy.h c:\mingw\include\_mingw.h
pem_err.o: c:\mingw\include\errno.h c:\mingw\include\msvcrtver.h
pem_err.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
pem_err.o: c:\mingw\include\stdlib.h c:\mingw\include\sys/types.h
pem_err.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
pem_err.o: c:\mingw\include\w32api.h
pem_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pem_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pem_err.c
pem_info.o: ../../e_os.h ../../include/openssl/asn1.h
pem_info.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
pem_info.o: ../../include/openssl/crypto.h ../../include/openssl/dsa.h
pem_info.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
pem_info.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
pem_info.o: ../../include/openssl/err.h ../../include/openssl/evp.h
pem_info.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
pem_info.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
pem_info.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
pem_info.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
pem_info.o: ../../include/openssl/pkcs7.h ../../include/openssl/rsa.h
pem_info.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
pem_info.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
pem_info.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
pem_info.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
pem_info.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
pem_info.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
pem_info.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
pem_info.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
pem_info.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
pem_info.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
pem_info.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
pem_info.o: c:\mingw\include\string.h c:\mingw\include\strings.h
pem_info.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
pem_info.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
pem_info.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
pem_info.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
pem_info.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
pem_info.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
pem_info.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
pem_info.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
pem_info.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
pem_info.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
pem_info.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pem_info.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pem_info.c
pem_lib.o: ../../e_os.h ../../include/openssl/asn1.h
pem_lib.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
pem_lib.o: ../../include/openssl/crypto.h ../../include/openssl/des.h
pem_lib.o: ../../include/openssl/des_old.h ../../include/openssl/e_os2.h
pem_lib.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
pem_lib.o: ../../include/openssl/ecdsa.h ../../include/openssl/engine.h
pem_lib.o: ../../include/openssl/err.h ../../include/openssl/evp.h
pem_lib.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
pem_lib.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
pem_lib.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
pem_lib.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
pem_lib.o: ../../include/openssl/pkcs12.h ../../include/openssl/pkcs7.h
pem_lib.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
pem_lib.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
pem_lib.o: ../../include/openssl/symhacks.h ../../include/openssl/ui.h
pem_lib.o: ../../include/openssl/ui_compat.h ../../include/openssl/x509.h
pem_lib.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
pem_lib.o: ../../ms/uplink.h ../asn1/asn1_locl.h ../cryptlib.h
pem_lib.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
pem_lib.o: c:\mingw\include\ctype.h c:\mingw\include\dbt.h
pem_lib.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
pem_lib.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
pem_lib.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
pem_lib.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
pem_lib.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
pem_lib.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
pem_lib.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
pem_lib.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
pem_lib.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
pem_lib.o: c:\mingw\include\wctype.h c:\mingw\include\winbase.h
pem_lib.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
pem_lib.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
pem_lib.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
pem_lib.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
pem_lib.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
pem_lib.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
pem_lib.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
pem_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pem_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pem_lib.c
pem_oth.o: ../../e_os.h ../../include/openssl/asn1.h
pem_oth.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
pem_oth.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
pem_oth.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
pem_oth.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
pem_oth.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
pem_oth.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
pem_oth.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
pem_oth.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pem.h
pem_oth.o: ../../include/openssl/pem2.h ../../include/openssl/pkcs7.h
pem_oth.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
pem_oth.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
pem_oth.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
pem_oth.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
pem_oth.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
pem_oth.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
pem_oth.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
pem_oth.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
pem_oth.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
pem_oth.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
pem_oth.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
pem_oth.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
pem_oth.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
pem_oth.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
pem_oth.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
pem_oth.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
pem_oth.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
pem_oth.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
pem_oth.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
pem_oth.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
pem_oth.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
pem_oth.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
pem_oth.o: c:\mingw\include\ws2tcpip.h
pem_oth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pem_oth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pem_oth.c
pem_pk8.o: ../../e_os.h ../../include/openssl/asn1.h
pem_pk8.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
pem_pk8.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
pem_pk8.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
pem_pk8.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
pem_pk8.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
pem_pk8.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
pem_pk8.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
pem_pk8.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pem.h
pem_pk8.o: ../../include/openssl/pem2.h ../../include/openssl/pkcs12.h
pem_pk8.o: ../../include/openssl/pkcs7.h ../../include/openssl/rand.h
pem_pk8.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
pem_pk8.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
pem_pk8.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
pem_pk8.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
pem_pk8.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
pem_pk8.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
pem_pk8.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
pem_pk8.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
pem_pk8.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
pem_pk8.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
pem_pk8.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
pem_pk8.o: c:\mingw\include\string.h c:\mingw\include\strings.h
pem_pk8.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
pem_pk8.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
pem_pk8.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
pem_pk8.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
pem_pk8.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
pem_pk8.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
pem_pk8.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
pem_pk8.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
pem_pk8.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
pem_pk8.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
pem_pk8.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pem_pk8.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pem_pk8.c
pem_pkey.o: ../../e_os.h ../../include/openssl/asn1.h
pem_pkey.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
pem_pkey.o: ../../include/openssl/crypto.h ../../include/openssl/dh.h
pem_pkey.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
pem_pkey.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
pem_pkey.o: ../../include/openssl/engine.h ../../include/openssl/err.h
pem_pkey.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
pem_pkey.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
pem_pkey.o: ../../include/openssl/opensslconf.h
pem_pkey.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
pem_pkey.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
pem_pkey.o: ../../include/openssl/pkcs12.h ../../include/openssl/pkcs7.h
pem_pkey.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
pem_pkey.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
pem_pkey.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
pem_pkey.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
pem_pkey.o: ../../ms/uplink.h ../asn1/asn1_locl.h ../cryptlib.h
pem_pkey.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
pem_pkey.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
pem_pkey.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
pem_pkey.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
pem_pkey.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
pem_pkey.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
pem_pkey.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
pem_pkey.o: c:\mingw\include\string.h c:\mingw\include\strings.h
pem_pkey.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
pem_pkey.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
pem_pkey.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
pem_pkey.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
pem_pkey.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
pem_pkey.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
pem_pkey.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
pem_pkey.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
pem_pkey.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
pem_pkey.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
pem_pkey.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pem_pkey.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pem_pkey.c
pem_seal.o: ../../e_os.h ../../include/openssl/asn1.h
pem_seal.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
pem_seal.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
pem_seal.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
pem_seal.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
pem_seal.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
pem_seal.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
pem_seal.o: ../../include/openssl/opensslconf.h
pem_seal.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
pem_seal.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
pem_seal.o: ../../include/openssl/pkcs7.h ../../include/openssl/rand.h
pem_seal.o: ../../include/openssl/rsa.h ../../include/openssl/safestack.h
pem_seal.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
pem_seal.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
pem_seal.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
pem_seal.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
pem_seal.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
pem_seal.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
pem_seal.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
pem_seal.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
pem_seal.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
pem_seal.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
pem_seal.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
pem_seal.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
pem_seal.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
pem_seal.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
pem_seal.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
pem_seal.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
pem_seal.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
pem_seal.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
pem_seal.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
pem_seal.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
pem_seal.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
pem_seal.o: c:\mingw\include\ws2tcpip.h
pem_seal.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pem_seal.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pem_seal.c
pem_sign.o: ../../e_os.h ../../include/openssl/asn1.h
pem_sign.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
pem_sign.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
pem_sign.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
pem_sign.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
pem_sign.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
pem_sign.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
pem_sign.o: ../../include/openssl/opensslconf.h
pem_sign.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
pem_sign.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
pem_sign.o: ../../include/openssl/pkcs7.h ../../include/openssl/rand.h
pem_sign.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
pem_sign.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
pem_sign.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
pem_sign.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
pem_sign.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
pem_sign.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
pem_sign.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
pem_sign.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
pem_sign.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
pem_sign.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
pem_sign.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
pem_sign.o: c:\mingw\include\string.h c:\mingw\include\strings.h
pem_sign.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
pem_sign.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
pem_sign.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
pem_sign.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
pem_sign.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
pem_sign.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
pem_sign.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
pem_sign.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
pem_sign.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
pem_sign.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
pem_sign.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pem_sign.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pem_sign.c
pem_x509.o: ../../e_os.h ../../include/openssl/asn1.h
pem_x509.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
pem_x509.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
pem_x509.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
pem_x509.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
pem_x509.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
pem_x509.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
pem_x509.o: ../../include/openssl/opensslconf.h
pem_x509.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
pem_x509.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
pem_x509.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
pem_x509.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
pem_x509.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
pem_x509.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
pem_x509.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
pem_x509.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
pem_x509.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
pem_x509.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
pem_x509.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
pem_x509.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
pem_x509.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
pem_x509.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
pem_x509.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
pem_x509.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
pem_x509.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
pem_x509.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
pem_x509.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
pem_x509.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
pem_x509.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
pem_x509.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
pem_x509.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
pem_x509.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
pem_x509.o: c:\mingw\include\ws2tcpip.h
pem_x509.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pem_x509.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pem_x509.c
pem_xaux.o: ../../e_os.h ../../include/openssl/asn1.h
pem_xaux.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
pem_xaux.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
pem_xaux.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
pem_xaux.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
pem_xaux.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
pem_xaux.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
pem_xaux.o: ../../include/openssl/opensslconf.h
pem_xaux.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
pem_xaux.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
pem_xaux.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
pem_xaux.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
pem_xaux.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
pem_xaux.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
pem_xaux.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
pem_xaux.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
pem_xaux.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
pem_xaux.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
pem_xaux.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
pem_xaux.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
pem_xaux.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
pem_xaux.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
pem_xaux.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
pem_xaux.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
pem_xaux.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
pem_xaux.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
pem_xaux.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
pem_xaux.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
pem_xaux.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
pem_xaux.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
pem_xaux.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
pem_xaux.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
pem_xaux.o: c:\mingw\include\ws2tcpip.h
pem_xaux.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pem_xaux.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pem_xaux.c
pvkfmt.o: ../../e_os.h ../../include/openssl/asn1.h ../../include/openssl/bio.h
pvkfmt.o: ../../include/openssl/bn.h ../../include/openssl/buffer.h
pvkfmt.o: ../../include/openssl/crypto.h ../../include/openssl/dsa.h
pvkfmt.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
pvkfmt.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
pvkfmt.o: ../../include/openssl/err.h ../../include/openssl/evp.h
pvkfmt.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
pvkfmt.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
pvkfmt.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
pvkfmt.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
pvkfmt.o: ../../include/openssl/pkcs7.h ../../include/openssl/rand.h
pvkfmt.o: ../../include/openssl/rsa.h ../../include/openssl/safestack.h
pvkfmt.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
pvkfmt.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
pvkfmt.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c ../../ms/uplink.h
pvkfmt.o: ../cryptlib.h c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
pvkfmt.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
pvkfmt.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
pvkfmt.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
pvkfmt.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
pvkfmt.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
pvkfmt.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
pvkfmt.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
pvkfmt.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
pvkfmt.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
pvkfmt.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
pvkfmt.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
pvkfmt.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
pvkfmt.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
pvkfmt.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
pvkfmt.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
pvkfmt.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
pvkfmt.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
pvkfmt.o: c:\mingw\include\ws2tcpip.h
pvkfmt.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pvkfmt.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pvkfmt.c
