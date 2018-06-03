#
# OpenSSL/crypto/err/Makefile
#

DIR=	err
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
LIBSRC=err.c err_all.c err_prn.c
LIBOBJ=err.o err_all.o err_prn.o

SRC= $(LIBSRC)

EXHEADER= err.h
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

err.o: ../../e_os.h ../../include/openssl/bio.h ../../include/openssl/buffer.h
err.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
err.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
err.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
err.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
err.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
err.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
err.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
err.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h c:\mingw\include\fcntl.h
err.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
err.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
err.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
err.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
err.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
err.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
err.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
err.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
err.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
err.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
err.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
err.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
err.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
err.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
err.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h err.c
err_all.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
err_all.o: ../../include/openssl/bn.h ../../include/openssl/buffer.h
err_all.o: ../../include/openssl/cms.h ../../include/openssl/comp.h
err_all.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
err_all.o: ../../include/openssl/dh.h ../../include/openssl/dsa.h
err_all.o: ../../include/openssl/dso.h ../../include/openssl/e_os2.h
err_all.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
err_all.o: ../../include/openssl/ecdsa.h ../../include/openssl/engine.h
err_all.o: ../../include/openssl/err.h ../../include/openssl/evp.h
err_all.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
err_all.o: ../../include/openssl/objects.h ../../include/openssl/ocsp.h
err_all.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
err_all.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pem2.h
err_all.o: ../../include/openssl/pkcs12.h ../../include/openssl/pkcs7.h
err_all.o: ../../include/openssl/rand.h ../../include/openssl/rsa.h
err_all.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
err_all.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
err_all.o: ../../include/openssl/ts.h ../../include/openssl/ui.h
err_all.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
err_all.o: ../../include/openssl/x509v3.h c:\mingw\include\_mingw.h
err_all.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
err_all.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
err_all.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
err_all.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
err_all.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
err_all.o: c:\mingw\include\string.h c:\mingw\include\strings.h
err_all.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
err_all.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
err_all.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
err_all.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
err_all.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
err_all.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
err_all.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
err_all.o: c:\mingw\include\winreg.h c:\mingw\include\winsvc.h
err_all.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
err_all.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
err_all.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h err_all.c
err_prn.o: ../../e_os.h ../../include/openssl/bio.h
err_prn.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
err_prn.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
err_prn.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
err_prn.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
err_prn.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
err_prn.o: ../../include/openssl/symhacks.h ../../ms/applink.c
err_prn.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
err_prn.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
err_prn.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
err_prn.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
err_prn.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
err_prn.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
err_prn.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
err_prn.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
err_prn.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
err_prn.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
err_prn.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
err_prn.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
err_prn.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
err_prn.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
err_prn.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
err_prn.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
err_prn.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
err_prn.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
err_prn.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
err_prn.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h err_prn.c
