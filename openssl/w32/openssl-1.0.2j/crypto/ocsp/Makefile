#
# OpenSSL/ocsp/Makefile
#

DIR=	ocsp
TOP=	../..
CC=	cc
INCLUDES= -I.. -I$(TOP) -I../../include
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile README
TEST=
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC= ocsp_asn.c ocsp_ext.c ocsp_ht.c ocsp_lib.c ocsp_cl.c \
	ocsp_srv.c ocsp_prn.c ocsp_vfy.c ocsp_err.c

LIBOBJ= ocsp_asn.o ocsp_ext.o ocsp_ht.o ocsp_lib.o ocsp_cl.o \
	ocsp_srv.o ocsp_prn.o ocsp_vfy.o ocsp_err.o

SRC= $(LIBSRC)

EXHEADER= ocsp.h
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
	$(MAKEDEPEND) -- $(CFLAG) $(INCLUDES) $(DEPFLAG) -- $(LIBSRC)

dclean:
	$(PERL) -pe 'if (/^# DO NOT DELETE THIS LINE/) {print; exit(0);}' $(MAKEFILE) >Makefile.new
	mv -f Makefile.new $(MAKEFILE)

clean:
	rm -f *.o *.obj lib tags core .pure .nfs* *.old *.bak fluff

# DO NOT DELETE THIS LINE -- make depend depends on it.

ocsp_asn.o: ../../include/openssl/asn1.h ../../include/openssl/asn1t.h
ocsp_asn.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
ocsp_asn.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
ocsp_asn.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ocsp_asn.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
ocsp_asn.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
ocsp_asn.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
ocsp_asn.o: ../../include/openssl/ocsp.h ../../include/openssl/opensslconf.h
ocsp_asn.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ocsp_asn.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
ocsp_asn.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
ocsp_asn.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
ocsp_asn.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
ocsp_asn.o: c:\mingw\include\_mingw.h c:\mingw\include\msvcrtver.h
ocsp_asn.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
ocsp_asn.o: c:\mingw\include\stdlib.h c:\mingw\include\sys/types.h
ocsp_asn.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
ocsp_asn.o: c:\mingw\include\w32api.h
ocsp_asn.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ocsp_asn.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ocsp_asn.c
ocsp_cl.o: ../../e_os.h ../../include/openssl/asn1.h
ocsp_cl.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
ocsp_cl.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
ocsp_cl.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ocsp_cl.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
ocsp_cl.o: ../../include/openssl/err.h ../../include/openssl/evp.h
ocsp_cl.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
ocsp_cl.o: ../../include/openssl/objects.h ../../include/openssl/ocsp.h
ocsp_cl.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
ocsp_cl.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pem.h
ocsp_cl.o: ../../include/openssl/pem2.h ../../include/openssl/pkcs7.h
ocsp_cl.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
ocsp_cl.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
ocsp_cl.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
ocsp_cl.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
ocsp_cl.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
ocsp_cl.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
ocsp_cl.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
ocsp_cl.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
ocsp_cl.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
ocsp_cl.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
ocsp_cl.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
ocsp_cl.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ocsp_cl.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ocsp_cl.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ocsp_cl.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ocsp_cl.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
ocsp_cl.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
ocsp_cl.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
ocsp_cl.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
ocsp_cl.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
ocsp_cl.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
ocsp_cl.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
ocsp_cl.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
ocsp_cl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ocsp_cl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ocsp_cl.c
ocsp_err.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ocsp_err.o: ../../include/openssl/buffer.h ../../include/openssl/conf.h
ocsp_err.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
ocsp_err.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
ocsp_err.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
ocsp_err.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
ocsp_err.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
ocsp_err.o: ../../include/openssl/ocsp.h ../../include/openssl/opensslconf.h
ocsp_err.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ocsp_err.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
ocsp_err.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
ocsp_err.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
ocsp_err.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
ocsp_err.o: c:\mingw\include\_mingw.h c:\mingw\include\errno.h
ocsp_err.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ocsp_err.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ocsp_err.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ocsp_err.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ocsp_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ocsp_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ocsp_err.c
ocsp_ext.o: ../../e_os.h ../../include/openssl/asn1.h
ocsp_ext.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
ocsp_ext.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
ocsp_ext.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ocsp_ext.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
ocsp_ext.o: ../../include/openssl/err.h ../../include/openssl/evp.h
ocsp_ext.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
ocsp_ext.o: ../../include/openssl/objects.h ../../include/openssl/ocsp.h
ocsp_ext.o: ../../include/openssl/opensslconf.h
ocsp_ext.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ocsp_ext.o: ../../include/openssl/pkcs7.h ../../include/openssl/rand.h
ocsp_ext.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
ocsp_ext.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
ocsp_ext.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
ocsp_ext.o: ../../include/openssl/x509v3.h ../../ms/applink.c ../../ms/uplink.h
ocsp_ext.o: ../cryptlib.h c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
ocsp_ext.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
ocsp_ext.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
ocsp_ext.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
ocsp_ext.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
ocsp_ext.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
ocsp_ext.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ocsp_ext.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ocsp_ext.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ocsp_ext.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ocsp_ext.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
ocsp_ext.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
ocsp_ext.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
ocsp_ext.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
ocsp_ext.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
ocsp_ext.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
ocsp_ext.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
ocsp_ext.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
ocsp_ext.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ocsp_ext.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ocsp_ext.c
ocsp_ht.o: ../../e_os.h ../../include/openssl/asn1.h
ocsp_ht.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
ocsp_ht.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
ocsp_ht.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ocsp_ht.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
ocsp_ht.o: ../../include/openssl/err.h ../../include/openssl/evp.h
ocsp_ht.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
ocsp_ht.o: ../../include/openssl/objects.h ../../include/openssl/ocsp.h
ocsp_ht.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
ocsp_ht.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pkcs7.h
ocsp_ht.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
ocsp_ht.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
ocsp_ht.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
ocsp_ht.o: ../../include/openssl/x509v3.h c:\mingw\include\_mingw.h
ocsp_ht.o: c:\mingw\include\basetsd.h c:\mingw\include\ctype.h
ocsp_ht.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
ocsp_ht.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
ocsp_ht.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
ocsp_ht.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
ocsp_ht.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
ocsp_ht.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ocsp_ht.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ocsp_ht.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ocsp_ht.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ocsp_ht.o: c:\mingw\include\wchar.h c:\mingw\include\wctype.h
ocsp_ht.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
ocsp_ht.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
ocsp_ht.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
ocsp_ht.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
ocsp_ht.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
ocsp_ht.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
ocsp_ht.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
ocsp_ht.o: c:\mingw\include\ws2tcpip.h
ocsp_ht.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ocsp_ht.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ocsp_ht.c
ocsp_lib.o: ../../e_os.h ../../include/openssl/asn1.h
ocsp_lib.o: ../../include/openssl/asn1t.h ../../include/openssl/bio.h
ocsp_lib.o: ../../include/openssl/buffer.h ../../include/openssl/conf.h
ocsp_lib.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
ocsp_lib.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
ocsp_lib.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
ocsp_lib.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
ocsp_lib.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
ocsp_lib.o: ../../include/openssl/ocsp.h ../../include/openssl/opensslconf.h
ocsp_lib.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ocsp_lib.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
ocsp_lib.o: ../../include/openssl/pkcs7.h ../../include/openssl/rand.h
ocsp_lib.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
ocsp_lib.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
ocsp_lib.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
ocsp_lib.o: ../../include/openssl/x509v3.h ../../ms/applink.c ../../ms/uplink.h
ocsp_lib.o: ../cryptlib.h c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
ocsp_lib.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
ocsp_lib.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
ocsp_lib.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
ocsp_lib.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
ocsp_lib.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
ocsp_lib.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ocsp_lib.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ocsp_lib.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ocsp_lib.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ocsp_lib.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
ocsp_lib.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
ocsp_lib.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
ocsp_lib.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
ocsp_lib.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
ocsp_lib.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
ocsp_lib.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
ocsp_lib.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
ocsp_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ocsp_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ocsp_lib.c
ocsp_prn.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ocsp_prn.o: ../../include/openssl/buffer.h ../../include/openssl/conf.h
ocsp_prn.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
ocsp_prn.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
ocsp_prn.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
ocsp_prn.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
ocsp_prn.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
ocsp_prn.o: ../../include/openssl/ocsp.h ../../include/openssl/opensslconf.h
ocsp_prn.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ocsp_prn.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
ocsp_prn.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
ocsp_prn.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
ocsp_prn.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
ocsp_prn.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
ocsp_prn.o: c:\mingw\include\_mingw.h c:\mingw\include\errno.h
ocsp_prn.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ocsp_prn.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ocsp_prn.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ocsp_prn.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ocsp_prn.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ocsp_prn.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ocsp_prn.c
ocsp_srv.o: ../../e_os.h ../../include/openssl/asn1.h
ocsp_srv.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
ocsp_srv.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
ocsp_srv.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ocsp_srv.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
ocsp_srv.o: ../../include/openssl/err.h ../../include/openssl/evp.h
ocsp_srv.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
ocsp_srv.o: ../../include/openssl/objects.h ../../include/openssl/ocsp.h
ocsp_srv.o: ../../include/openssl/opensslconf.h
ocsp_srv.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ocsp_srv.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
ocsp_srv.o: ../../include/openssl/pkcs7.h ../../include/openssl/rand.h
ocsp_srv.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
ocsp_srv.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
ocsp_srv.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
ocsp_srv.o: ../../include/openssl/x509v3.h ../../ms/applink.c ../../ms/uplink.h
ocsp_srv.o: ../cryptlib.h c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
ocsp_srv.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
ocsp_srv.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
ocsp_srv.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
ocsp_srv.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
ocsp_srv.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
ocsp_srv.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ocsp_srv.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ocsp_srv.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ocsp_srv.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ocsp_srv.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
ocsp_srv.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
ocsp_srv.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
ocsp_srv.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
ocsp_srv.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
ocsp_srv.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
ocsp_srv.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
ocsp_srv.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
ocsp_srv.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ocsp_srv.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ocsp_srv.c
ocsp_vfy.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ocsp_vfy.o: ../../include/openssl/buffer.h ../../include/openssl/conf.h
ocsp_vfy.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
ocsp_vfy.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
ocsp_vfy.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
ocsp_vfy.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
ocsp_vfy.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
ocsp_vfy.o: ../../include/openssl/ocsp.h ../../include/openssl/opensslconf.h
ocsp_vfy.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ocsp_vfy.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
ocsp_vfy.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
ocsp_vfy.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
ocsp_vfy.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
ocsp_vfy.o: c:\mingw\include\_mingw.h c:\mingw\include\errno.h
ocsp_vfy.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ocsp_vfy.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ocsp_vfy.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ocsp_vfy.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ocsp_vfy.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ocsp_vfy.o: c:\mingw\include\wchar.h
ocsp_vfy.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ocsp_vfy.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ocsp_vfy.c
