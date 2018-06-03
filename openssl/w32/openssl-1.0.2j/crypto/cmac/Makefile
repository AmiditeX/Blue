#
# OpenSSL/crypto/cmac/Makefile
#

DIR=	cmac
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
LIBSRC=cmac.c cm_ameth.c cm_pmeth.c
LIBOBJ=cmac.o cm_ameth.o cm_pmeth.o

SRC= $(LIBSRC)

EXHEADER= cmac.h
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

cm_ameth.o: ../../e_os.h ../../include/openssl/asn1.h
cm_ameth.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
cm_ameth.o: ../../include/openssl/cmac.h ../../include/openssl/crypto.h
cm_ameth.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
cm_ameth.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
cm_ameth.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
cm_ameth.o: ../../include/openssl/opensslconf.h
cm_ameth.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
cm_ameth.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
cm_ameth.o: ../../include/openssl/symhacks.h ../../ms/applink.c
cm_ameth.o: ../../ms/uplink.h ../asn1/asn1_locl.h ../cryptlib.h
cm_ameth.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
cm_ameth.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
cm_ameth.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
cm_ameth.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
cm_ameth.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
cm_ameth.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
cm_ameth.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
cm_ameth.o: c:\mingw\include\string.h c:\mingw\include\strings.h
cm_ameth.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
cm_ameth.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
cm_ameth.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
cm_ameth.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
cm_ameth.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
cm_ameth.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
cm_ameth.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
cm_ameth.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
cm_ameth.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
cm_ameth.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
cm_ameth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
cm_ameth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h cm_ameth.c
cm_pmeth.o: ../../e_os.h ../../include/openssl/asn1.h
cm_pmeth.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
cm_pmeth.o: ../../include/openssl/cmac.h ../../include/openssl/conf.h
cm_pmeth.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
cm_pmeth.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
cm_pmeth.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
cm_pmeth.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
cm_pmeth.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
cm_pmeth.o: ../../include/openssl/opensslconf.h
cm_pmeth.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
cm_pmeth.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
cm_pmeth.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
cm_pmeth.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
cm_pmeth.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
cm_pmeth.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
cm_pmeth.o: ../evp/evp_locl.h c:\mingw\include\_mingw.h
cm_pmeth.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
cm_pmeth.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
cm_pmeth.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
cm_pmeth.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
cm_pmeth.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
cm_pmeth.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
cm_pmeth.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
cm_pmeth.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
cm_pmeth.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
cm_pmeth.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
cm_pmeth.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
cm_pmeth.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
cm_pmeth.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
cm_pmeth.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
cm_pmeth.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
cm_pmeth.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
cm_pmeth.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
cm_pmeth.o: c:\mingw\include\ws2tcpip.h
cm_pmeth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
cm_pmeth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h cm_pmeth.c
cmac.o: ../../e_os.h ../../include/openssl/asn1.h ../../include/openssl/bio.h
cmac.o: ../../include/openssl/buffer.h ../../include/openssl/cmac.h
cmac.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
cmac.o: ../../include/openssl/err.h ../../include/openssl/evp.h
cmac.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
cmac.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
cmac.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
cmac.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
cmac.o: ../../include/openssl/symhacks.h ../../ms/applink.c ../../ms/uplink.h
cmac.o: ../cryptlib.h c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
cmac.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
cmac.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
cmac.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
cmac.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
cmac.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
cmac.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
cmac.o: c:\mingw\include\string.h c:\mingw\include\strings.h
cmac.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
cmac.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
cmac.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
cmac.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
cmac.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
cmac.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
cmac.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
cmac.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
cmac.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
cmac.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
cmac.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
cmac.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h cmac.c
