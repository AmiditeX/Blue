#
# OpenSSL/crypto/rand/Makefile
#

DIR=	rand
TOP=	../..
CC=	cc
INCLUDES=
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile
TEST= randtest.c
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC=md_rand.c randfile.c rand_lib.c rand_err.c rand_egd.c \
	rand_win.c rand_unix.c rand_os2.c rand_nw.c
LIBOBJ=md_rand.o randfile.o rand_lib.o rand_err.o rand_egd.o \
	rand_win.o rand_unix.o rand_os2.o rand_nw.o

SRC= $(LIBSRC)

EXHEADER= rand.h
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

md_rand.o: ../../e_os.h ../../include/openssl/asn1.h
md_rand.o: ../../include/openssl/bio.h ../../include/openssl/crypto.h
md_rand.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
md_rand.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
md_rand.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
md_rand.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
md_rand.o: ../../include/openssl/ossl_typ.h ../../include/openssl/rand.h
md_rand.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
md_rand.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
md_rand.o: c:\mingw\include\_mingw.h c:\mingw\include\assert.h
md_rand.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
md_rand.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
md_rand.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
md_rand.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
md_rand.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
md_rand.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
md_rand.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
md_rand.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
md_rand.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
md_rand.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
md_rand.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
md_rand.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
md_rand.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
md_rand.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
md_rand.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
md_rand.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
md_rand.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
md_rand.o: c:\mingw\include\ws2tcpip.h
md_rand.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
md_rand.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h md_rand.c rand_lcl.h
rand_egd.o: ../../include/openssl/buffer.h ../../include/openssl/e_os2.h
rand_egd.o: ../../include/openssl/opensslconf.h
rand_egd.o: ../../include/openssl/ossl_typ.h ../../include/openssl/rand.h
rand_egd.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
rand_egd.o: c:\mingw\include\dbt.h c:\mingw\include\msvcrtver.h
rand_egd.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
rand_egd.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdlib.h
rand_egd.o: c:\mingw\include\string.h c:\mingw\include\strings.h
rand_egd.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
rand_egd.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
rand_egd.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
rand_egd.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
rand_egd.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
rand_egd.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
rand_egd.o: c:\mingw\include\winreg.h c:\mingw\include\winsvc.h
rand_egd.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
rand_egd.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rand_egd.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rand_egd.c
rand_err.o: ../../include/openssl/bio.h ../../include/openssl/crypto.h
rand_err.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
rand_err.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
rand_err.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
rand_err.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
rand_err.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
rand_err.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
rand_err.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
rand_err.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
rand_err.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
rand_err.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
rand_err.o: c:\mingw\include\string.h c:\mingw\include\strings.h
rand_err.o: c:\mingw\include\sys/types.h c:\mingw\include\w32api.h
rand_err.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
rand_err.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
rand_err.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
rand_err.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
rand_err.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
rand_err.o: c:\mingw\include\winreg.h c:\mingw\include\winsvc.h
rand_err.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
rand_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rand_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rand_err.c
rand_lib.o: ../../e_os.h ../../include/openssl/asn1.h
rand_lib.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
rand_lib.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
rand_lib.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
rand_lib.o: ../../include/openssl/ecdsa.h ../../include/openssl/engine.h
rand_lib.o: ../../include/openssl/err.h ../../include/openssl/evp.h
rand_lib.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
rand_lib.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
rand_lib.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
rand_lib.o: ../../include/openssl/pkcs7.h ../../include/openssl/rand.h
rand_lib.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
rand_lib.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
rand_lib.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
rand_lib.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
rand_lib.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
rand_lib.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
rand_lib.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
rand_lib.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
rand_lib.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
rand_lib.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
rand_lib.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
rand_lib.o: c:\mingw\include\string.h c:\mingw\include\strings.h
rand_lib.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
rand_lib.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
rand_lib.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
rand_lib.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
rand_lib.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
rand_lib.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
rand_lib.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
rand_lib.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
rand_lib.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
rand_lib.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
rand_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rand_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rand_lib.c
rand_nw.o: ../../e_os.h ../../include/openssl/asn1.h
rand_nw.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
rand_nw.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
rand_nw.o: ../../include/openssl/err.h ../../include/openssl/evp.h
rand_nw.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
rand_nw.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
rand_nw.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
rand_nw.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
rand_nw.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
rand_nw.o: ../../include/openssl/symhacks.h ../../ms/applink.c
rand_nw.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
rand_nw.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
rand_nw.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
rand_nw.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
rand_nw.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
rand_nw.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
rand_nw.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
rand_nw.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
rand_nw.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
rand_nw.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
rand_nw.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
rand_nw.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
rand_nw.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
rand_nw.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
rand_nw.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
rand_nw.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
rand_nw.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
rand_nw.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
rand_nw.o: c:\mingw\include\ws2tcpip.h
rand_nw.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rand_nw.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rand_lcl.h rand_nw.c
rand_os2.o: ../../e_os.h ../../include/openssl/asn1.h
rand_os2.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
rand_os2.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
rand_os2.o: ../../include/openssl/err.h ../../include/openssl/evp.h
rand_os2.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
rand_os2.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
rand_os2.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
rand_os2.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
rand_os2.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
rand_os2.o: ../../include/openssl/symhacks.h ../../ms/applink.c
rand_os2.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
rand_os2.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
rand_os2.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
rand_os2.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
rand_os2.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
rand_os2.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
rand_os2.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
rand_os2.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
rand_os2.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
rand_os2.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
rand_os2.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
rand_os2.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
rand_os2.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
rand_os2.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
rand_os2.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
rand_os2.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
rand_os2.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
rand_os2.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
rand_os2.o: c:\mingw\include\ws2tcpip.h
rand_os2.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rand_os2.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rand_lcl.h
rand_os2.o: rand_os2.c
rand_unix.o: ../../e_os.h ../../include/openssl/asn1.h
rand_unix.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
rand_unix.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
rand_unix.o: ../../include/openssl/err.h ../../include/openssl/evp.h
rand_unix.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
rand_unix.o: ../../include/openssl/objects.h
rand_unix.o: ../../include/openssl/opensslconf.h
rand_unix.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
rand_unix.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
rand_unix.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
rand_unix.o: ../../include/openssl/symhacks.h ../../ms/applink.c
rand_unix.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
rand_unix.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
rand_unix.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
rand_unix.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
rand_unix.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
rand_unix.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
rand_unix.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
rand_unix.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
rand_unix.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
rand_unix.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
rand_unix.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
rand_unix.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
rand_unix.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
rand_unix.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
rand_unix.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
rand_unix.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
rand_unix.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
rand_unix.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
rand_unix.o: c:\mingw\include\ws2tcpip.h
rand_unix.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rand_unix.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rand_lcl.h
rand_unix.o: rand_unix.c
rand_win.o: ../../e_os.h ../../include/openssl/asn1.h
rand_win.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
rand_win.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
rand_win.o: ../../include/openssl/err.h ../../include/openssl/evp.h
rand_win.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
rand_win.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
rand_win.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
rand_win.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
rand_win.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
rand_win.o: ../../include/openssl/symhacks.h ../../ms/applink.c
rand_win.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
rand_win.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
rand_win.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
rand_win.o: c:\mingw\include\io.h c:\mingw\include\lmcons.h
rand_win.o: c:\mingw\include\lmstats.h c:\mingw\include\malloc.h
rand_win.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
rand_win.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
rand_win.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
rand_win.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
rand_win.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
rand_win.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
rand_win.o: c:\mingw\include\tlhelp32.h c:\mingw\include\w32api.h
rand_win.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
rand_win.o: c:\mingw\include\wincon.h c:\mingw\include\wincrypt.h
rand_win.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
rand_win.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
rand_win.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
rand_win.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
rand_win.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
rand_win.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
rand_win.o: c:\mingw\include\ws2tcpip.h
rand_win.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rand_win.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rand_lcl.h
rand_win.o: rand_win.c
randfile.o: ../../e_os.h ../../include/openssl/buffer.h
randfile.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
randfile.o: ../../include/openssl/opensslconf.h
randfile.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
randfile.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
randfile.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
randfile.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
randfile.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
randfile.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
randfile.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
randfile.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
randfile.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
randfile.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
randfile.o: c:\mingw\include\string.h c:\mingw\include\strings.h
randfile.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\stat.h
randfile.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
randfile.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
randfile.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
randfile.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
randfile.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
randfile.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
randfile.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
randfile.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
randfile.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
randfile.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
randfile.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h randfile.c
