#
# OpenSSL/crypto/pkcs12/Makefile
#

DIR=	pkcs12
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
LIBSRC= p12_add.c p12_asn.c p12_attr.c p12_crpt.c p12_crt.c p12_decr.c \
	p12_init.c p12_key.c p12_kiss.c p12_mutl.c\
	p12_utl.c p12_npas.c pk12err.c p12_p8d.c p12_p8e.c
LIBOBJ= p12_add.o p12_asn.o p12_attr.o p12_crpt.o p12_crt.o p12_decr.o \
	p12_init.o p12_key.o p12_kiss.o p12_mutl.o\
	p12_utl.o p12_npas.o pk12err.o p12_p8d.o p12_p8e.o

SRC= $(LIBSRC)

EXHEADER=  pkcs12.h
HEADER=	$(EXHEADER)

ALL=    $(GENERAL) $(SRC) $(HEADER)

top:
	(cd ../..; $(MAKE) DIRS=crypto SDIRS=$(DIR) sub_all)

test:

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

p12_add.o: ../../e_os.h ../../include/openssl/asn1.h
p12_add.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
p12_add.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
p12_add.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
p12_add.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
p12_add.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
p12_add.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
p12_add.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
p12_add.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pkcs12.h
p12_add.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
p12_add.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
p12_add.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
p12_add.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
p12_add.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
p12_add.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
p12_add.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
p12_add.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
p12_add.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
p12_add.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
p12_add.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
p12_add.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
p12_add.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
p12_add.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
p12_add.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
p12_add.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
p12_add.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
p12_add.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
p12_add.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
p12_add.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
p12_add.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
p12_add.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
p12_add.o: c:\mingw\include\ws2tcpip.h
p12_add.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_add.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_add.c
p12_asn.o: ../../e_os.h ../../include/openssl/asn1.h
p12_asn.o: ../../include/openssl/asn1t.h ../../include/openssl/bio.h
p12_asn.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
p12_asn.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
p12_asn.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
p12_asn.o: ../../include/openssl/err.h ../../include/openssl/evp.h
p12_asn.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
p12_asn.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
p12_asn.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
p12_asn.o: ../../include/openssl/pkcs12.h ../../include/openssl/pkcs7.h
p12_asn.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
p12_asn.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
p12_asn.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
p12_asn.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
p12_asn.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
p12_asn.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
p12_asn.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
p12_asn.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
p12_asn.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
p12_asn.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
p12_asn.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
p12_asn.o: c:\mingw\include\string.h c:\mingw\include\strings.h
p12_asn.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
p12_asn.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
p12_asn.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
p12_asn.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
p12_asn.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
p12_asn.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
p12_asn.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
p12_asn.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
p12_asn.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
p12_asn.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
p12_asn.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_asn.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_asn.c
p12_attr.o: ../../e_os.h ../../include/openssl/asn1.h
p12_attr.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
p12_attr.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
p12_attr.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
p12_attr.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
p12_attr.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
p12_attr.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
p12_attr.o: ../../include/openssl/opensslconf.h
p12_attr.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
p12_attr.o: ../../include/openssl/pkcs12.h ../../include/openssl/pkcs7.h
p12_attr.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
p12_attr.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
p12_attr.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
p12_attr.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
p12_attr.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
p12_attr.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
p12_attr.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
p12_attr.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
p12_attr.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
p12_attr.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
p12_attr.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
p12_attr.o: c:\mingw\include\string.h c:\mingw\include\strings.h
p12_attr.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
p12_attr.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
p12_attr.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
p12_attr.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
p12_attr.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
p12_attr.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
p12_attr.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
p12_attr.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
p12_attr.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
p12_attr.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
p12_attr.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_attr.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_attr.c
p12_crpt.o: ../../e_os.h ../../include/openssl/asn1.h
p12_crpt.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
p12_crpt.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
p12_crpt.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
p12_crpt.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
p12_crpt.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
p12_crpt.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
p12_crpt.o: ../../include/openssl/opensslconf.h
p12_crpt.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
p12_crpt.o: ../../include/openssl/pkcs12.h ../../include/openssl/pkcs7.h
p12_crpt.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
p12_crpt.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
p12_crpt.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
p12_crpt.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
p12_crpt.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
p12_crpt.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
p12_crpt.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
p12_crpt.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
p12_crpt.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
p12_crpt.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
p12_crpt.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
p12_crpt.o: c:\mingw\include\string.h c:\mingw\include\strings.h
p12_crpt.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
p12_crpt.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
p12_crpt.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
p12_crpt.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
p12_crpt.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
p12_crpt.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
p12_crpt.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
p12_crpt.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
p12_crpt.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
p12_crpt.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
p12_crpt.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_crpt.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_crpt.c
p12_crt.o: ../../e_os.h ../../include/openssl/asn1.h
p12_crt.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
p12_crt.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
p12_crt.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
p12_crt.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
p12_crt.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
p12_crt.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
p12_crt.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
p12_crt.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pkcs12.h
p12_crt.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
p12_crt.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
p12_crt.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
p12_crt.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
p12_crt.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
p12_crt.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
p12_crt.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
p12_crt.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
p12_crt.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
p12_crt.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
p12_crt.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
p12_crt.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
p12_crt.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
p12_crt.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
p12_crt.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
p12_crt.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
p12_crt.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
p12_crt.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
p12_crt.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
p12_crt.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
p12_crt.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
p12_crt.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
p12_crt.o: c:\mingw\include\ws2tcpip.h
p12_crt.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_crt.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_crt.c
p12_decr.o: ../../e_os.h ../../include/openssl/asn1.h
p12_decr.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
p12_decr.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
p12_decr.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
p12_decr.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
p12_decr.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
p12_decr.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
p12_decr.o: ../../include/openssl/opensslconf.h
p12_decr.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
p12_decr.o: ../../include/openssl/pkcs12.h ../../include/openssl/pkcs7.h
p12_decr.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
p12_decr.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
p12_decr.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
p12_decr.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
p12_decr.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
p12_decr.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
p12_decr.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
p12_decr.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
p12_decr.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
p12_decr.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
p12_decr.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
p12_decr.o: c:\mingw\include\string.h c:\mingw\include\strings.h
p12_decr.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
p12_decr.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
p12_decr.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
p12_decr.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
p12_decr.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
p12_decr.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
p12_decr.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
p12_decr.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
p12_decr.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
p12_decr.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
p12_decr.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_decr.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_decr.c
p12_init.o: ../../e_os.h ../../include/openssl/asn1.h
p12_init.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
p12_init.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
p12_init.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
p12_init.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
p12_init.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
p12_init.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
p12_init.o: ../../include/openssl/opensslconf.h
p12_init.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
p12_init.o: ../../include/openssl/pkcs12.h ../../include/openssl/pkcs7.h
p12_init.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
p12_init.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
p12_init.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
p12_init.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
p12_init.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
p12_init.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
p12_init.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
p12_init.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
p12_init.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
p12_init.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
p12_init.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
p12_init.o: c:\mingw\include\string.h c:\mingw\include\strings.h
p12_init.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
p12_init.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
p12_init.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
p12_init.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
p12_init.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
p12_init.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
p12_init.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
p12_init.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
p12_init.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
p12_init.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
p12_init.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_init.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_init.c
p12_key.o: ../../e_os.h ../../include/openssl/asn1.h
p12_key.o: ../../include/openssl/bio.h ../../include/openssl/bn.h
p12_key.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
p12_key.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
p12_key.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
p12_key.o: ../../include/openssl/err.h ../../include/openssl/evp.h
p12_key.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
p12_key.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
p12_key.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
p12_key.o: ../../include/openssl/pkcs12.h ../../include/openssl/pkcs7.h
p12_key.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
p12_key.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
p12_key.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
p12_key.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
p12_key.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
p12_key.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
p12_key.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
p12_key.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
p12_key.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
p12_key.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
p12_key.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
p12_key.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
p12_key.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
p12_key.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
p12_key.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
p12_key.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
p12_key.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
p12_key.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
p12_key.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
p12_key.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
p12_key.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
p12_key.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
p12_key.o: c:\mingw\include\ws2tcpip.h
p12_key.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_key.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_key.c
p12_kiss.o: ../../e_os.h ../../include/openssl/asn1.h
p12_kiss.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
p12_kiss.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
p12_kiss.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
p12_kiss.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
p12_kiss.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
p12_kiss.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
p12_kiss.o: ../../include/openssl/opensslconf.h
p12_kiss.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
p12_kiss.o: ../../include/openssl/pkcs12.h ../../include/openssl/pkcs7.h
p12_kiss.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
p12_kiss.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
p12_kiss.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
p12_kiss.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
p12_kiss.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
p12_kiss.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
p12_kiss.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
p12_kiss.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
p12_kiss.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
p12_kiss.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
p12_kiss.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
p12_kiss.o: c:\mingw\include\string.h c:\mingw\include\strings.h
p12_kiss.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
p12_kiss.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
p12_kiss.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
p12_kiss.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
p12_kiss.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
p12_kiss.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
p12_kiss.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
p12_kiss.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
p12_kiss.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
p12_kiss.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
p12_kiss.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_kiss.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_kiss.c
p12_mutl.o: ../../e_os.h ../../include/openssl/asn1.h
p12_mutl.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
p12_mutl.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
p12_mutl.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
p12_mutl.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
p12_mutl.o: ../../include/openssl/evp.h ../../include/openssl/hmac.h
p12_mutl.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
p12_mutl.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
p12_mutl.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
p12_mutl.o: ../../include/openssl/pkcs12.h ../../include/openssl/pkcs7.h
p12_mutl.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
p12_mutl.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
p12_mutl.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
p12_mutl.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
p12_mutl.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
p12_mutl.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
p12_mutl.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
p12_mutl.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
p12_mutl.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
p12_mutl.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
p12_mutl.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
p12_mutl.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
p12_mutl.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
p12_mutl.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
p12_mutl.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
p12_mutl.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
p12_mutl.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
p12_mutl.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
p12_mutl.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
p12_mutl.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
p12_mutl.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
p12_mutl.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
p12_mutl.o: c:\mingw\include\ws2tcpip.h
p12_mutl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_mutl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_mutl.c
p12_npas.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
p12_npas.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
p12_npas.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
p12_npas.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
p12_npas.o: ../../include/openssl/err.h ../../include/openssl/evp.h
p12_npas.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
p12_npas.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
p12_npas.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
p12_npas.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
p12_npas.o: ../../include/openssl/pkcs12.h ../../include/openssl/pkcs7.h
p12_npas.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
p12_npas.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
p12_npas.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
p12_npas.o: c:\mingw\include\_mingw.h c:\mingw\include\errno.h
p12_npas.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
p12_npas.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
p12_npas.o: c:\mingw\include\string.h c:\mingw\include\strings.h
p12_npas.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
p12_npas.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
p12_npas.o: c:\mingw\include\wchar.h
p12_npas.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_npas.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_npas.c
p12_p8d.o: ../../e_os.h ../../include/openssl/asn1.h
p12_p8d.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
p12_p8d.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
p12_p8d.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
p12_p8d.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
p12_p8d.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
p12_p8d.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
p12_p8d.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
p12_p8d.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pkcs12.h
p12_p8d.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
p12_p8d.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
p12_p8d.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
p12_p8d.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
p12_p8d.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
p12_p8d.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
p12_p8d.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
p12_p8d.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
p12_p8d.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
p12_p8d.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
p12_p8d.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
p12_p8d.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
p12_p8d.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
p12_p8d.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
p12_p8d.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
p12_p8d.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
p12_p8d.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
p12_p8d.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
p12_p8d.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
p12_p8d.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
p12_p8d.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
p12_p8d.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
p12_p8d.o: c:\mingw\include\ws2tcpip.h
p12_p8d.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_p8d.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_p8d.c
p12_p8e.o: ../../e_os.h ../../include/openssl/asn1.h
p12_p8e.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
p12_p8e.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
p12_p8e.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
p12_p8e.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
p12_p8e.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
p12_p8e.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
p12_p8e.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
p12_p8e.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pkcs12.h
p12_p8e.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
p12_p8e.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
p12_p8e.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
p12_p8e.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
p12_p8e.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
p12_p8e.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
p12_p8e.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
p12_p8e.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
p12_p8e.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
p12_p8e.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
p12_p8e.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
p12_p8e.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
p12_p8e.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
p12_p8e.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
p12_p8e.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
p12_p8e.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
p12_p8e.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
p12_p8e.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
p12_p8e.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
p12_p8e.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
p12_p8e.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
p12_p8e.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
p12_p8e.o: c:\mingw\include\ws2tcpip.h
p12_p8e.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_p8e.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_p8e.c
p12_utl.o: ../../e_os.h ../../include/openssl/asn1.h
p12_utl.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
p12_utl.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
p12_utl.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
p12_utl.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
p12_utl.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
p12_utl.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
p12_utl.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
p12_utl.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pkcs12.h
p12_utl.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
p12_utl.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
p12_utl.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
p12_utl.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
p12_utl.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
p12_utl.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
p12_utl.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
p12_utl.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
p12_utl.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
p12_utl.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
p12_utl.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
p12_utl.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
p12_utl.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
p12_utl.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
p12_utl.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
p12_utl.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
p12_utl.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
p12_utl.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
p12_utl.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
p12_utl.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
p12_utl.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
p12_utl.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
p12_utl.o: c:\mingw\include\ws2tcpip.h
p12_utl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
p12_utl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h p12_utl.c
pk12err.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
pk12err.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
pk12err.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
pk12err.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
pk12err.o: ../../include/openssl/err.h ../../include/openssl/evp.h
pk12err.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
pk12err.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
pk12err.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
pk12err.o: ../../include/openssl/pkcs12.h ../../include/openssl/pkcs7.h
pk12err.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
pk12err.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
pk12err.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
pk12err.o: c:\mingw\include\_mingw.h c:\mingw\include\errno.h
pk12err.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
pk12err.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
pk12err.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
pk12err.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
pk12err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
pk12err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h pk12err.c
