#
# OpenSSL/crypto/md/Makefile
#

DIR=	hmac
TOP=	../..
CC=	cc
INCLUDES=
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile
TEST=hmactest.c
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC=hmac.c hm_ameth.c hm_pmeth.c
LIBOBJ=hmac.o hm_ameth.o hm_pmeth.o

SRC= $(LIBSRC)

EXHEADER= hmac.h
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

hm_ameth.o: ../../e_os.h ../../include/openssl/asn1.h
hm_ameth.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
hm_ameth.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
hm_ameth.o: ../../include/openssl/err.h ../../include/openssl/evp.h
hm_ameth.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
hm_ameth.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
hm_ameth.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
hm_ameth.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
hm_ameth.o: ../../include/openssl/symhacks.h ../../ms/applink.c
hm_ameth.o: ../../ms/uplink.h ../asn1/asn1_locl.h ../cryptlib.h
hm_ameth.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
hm_ameth.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
hm_ameth.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
hm_ameth.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
hm_ameth.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
hm_ameth.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
hm_ameth.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
hm_ameth.o: c:\mingw\include\string.h c:\mingw\include\strings.h
hm_ameth.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
hm_ameth.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
hm_ameth.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
hm_ameth.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
hm_ameth.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
hm_ameth.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
hm_ameth.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
hm_ameth.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
hm_ameth.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
hm_ameth.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
hm_ameth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
hm_ameth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h hm_ameth.c
hm_pmeth.o: ../../e_os.h ../../include/openssl/asn1.h
hm_pmeth.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
hm_pmeth.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
hm_pmeth.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
hm_pmeth.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
hm_pmeth.o: ../../include/openssl/err.h ../../include/openssl/evp.h
hm_pmeth.o: ../../include/openssl/hmac.h ../../include/openssl/lhash.h
hm_pmeth.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
hm_pmeth.o: ../../include/openssl/opensslconf.h
hm_pmeth.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
hm_pmeth.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
hm_pmeth.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
hm_pmeth.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
hm_pmeth.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
hm_pmeth.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
hm_pmeth.o: ../evp/evp_locl.h c:\mingw\include\_mingw.h
hm_pmeth.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
hm_pmeth.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
hm_pmeth.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
hm_pmeth.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
hm_pmeth.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
hm_pmeth.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
hm_pmeth.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
hm_pmeth.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
hm_pmeth.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
hm_pmeth.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
hm_pmeth.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
hm_pmeth.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
hm_pmeth.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
hm_pmeth.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
hm_pmeth.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
hm_pmeth.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
hm_pmeth.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
hm_pmeth.o: c:\mingw\include\ws2tcpip.h
hm_pmeth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
hm_pmeth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h hm_pmeth.c
hmac.o: ../../e_os.h ../../include/openssl/asn1.h ../../include/openssl/bio.h
hmac.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
hmac.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
hmac.o: ../../include/openssl/evp.h ../../include/openssl/hmac.h
hmac.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
hmac.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
hmac.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
hmac.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
hmac.o: ../../include/openssl/symhacks.h ../../ms/applink.c ../../ms/uplink.h
hmac.o: ../cryptlib.h c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
hmac.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
hmac.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
hmac.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
hmac.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
hmac.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
hmac.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
hmac.o: c:\mingw\include\string.h c:\mingw\include\strings.h
hmac.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
hmac.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
hmac.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
hmac.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
hmac.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
hmac.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
hmac.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
hmac.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
hmac.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
hmac.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
hmac.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
hmac.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h hmac.c
