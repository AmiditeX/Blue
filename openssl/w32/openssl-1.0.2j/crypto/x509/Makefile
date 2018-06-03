#
# OpenSSL/crypto/x509/Makefile
#

DIR=	x509
TOP=	../..
CC=	cc
INCLUDES= -I.. -I$(TOP) -I../../include
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile README
TEST=verify_extra_test.c
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC=	x509_def.c x509_d2.c x509_r2x.c x509_cmp.c \
	x509_obj.c x509_req.c x509spki.c x509_vfy.c \
	x509_set.c x509cset.c x509rset.c x509_err.c \
	x509name.c x509_v3.c x509_ext.c x509_att.c \
	x509type.c x509_lu.c x_all.c x509_txt.c \
	x509_trs.c by_file.c by_dir.c x509_vpm.c
LIBOBJ= x509_def.o x509_d2.o x509_r2x.o x509_cmp.o \
	x509_obj.o x509_req.o x509spki.o x509_vfy.o \
	x509_set.o x509cset.o x509rset.o x509_err.o \
	x509name.o x509_v3.o x509_ext.o x509_att.o \
	x509type.o x509_lu.o x_all.o x509_txt.o \
	x509_trs.o by_file.o by_dir.o x509_vpm.o

SRC= $(LIBSRC)

EXHEADER= x509.h x509_vfy.h
HEADER=	$(EXHEADER) vpm_int.h

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

by_dir.o: ../../e_os.h ../../include/openssl/asn1.h ../../include/openssl/bio.h
by_dir.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
by_dir.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
by_dir.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
by_dir.o: ../../include/openssl/err.h ../../include/openssl/evp.h
by_dir.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
by_dir.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
by_dir.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
by_dir.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
by_dir.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
by_dir.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
by_dir.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c ../../ms/uplink.h
by_dir.o: ../cryptlib.h by_dir.c c:\mingw\include\_mingw.h
by_dir.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
by_dir.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
by_dir.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
by_dir.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
by_dir.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
by_dir.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
by_dir.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
by_dir.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
by_dir.o: c:\mingw\include\sys\stat.h c:\mingw\include\sys\types.h
by_dir.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
by_dir.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
by_dir.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
by_dir.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
by_dir.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
by_dir.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
by_dir.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
by_dir.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
by_dir.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
by_dir.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
by_dir.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
by_file.o: ../../e_os.h ../../include/openssl/asn1.h
by_file.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
by_file.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
by_file.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
by_file.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
by_file.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
by_file.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
by_file.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
by_file.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pem.h
by_file.o: ../../include/openssl/pem2.h ../../include/openssl/pkcs7.h
by_file.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
by_file.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
by_file.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
by_file.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h by_file.c
by_file.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
by_file.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
by_file.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
by_file.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
by_file.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
by_file.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
by_file.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
by_file.o: c:\mingw\include\string.h c:\mingw\include\strings.h
by_file.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
by_file.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
by_file.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
by_file.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
by_file.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
by_file.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
by_file.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
by_file.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
by_file.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
by_file.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
by_file.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
by_file.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
x509_att.o: ../../e_os.h ../../include/openssl/asn1.h
x509_att.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509_att.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
x509_att.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
x509_att.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
x509_att.o: ../../include/openssl/err.h ../../include/openssl/evp.h
x509_att.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
x509_att.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
x509_att.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_att.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_att.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_att.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_att.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
x509_att.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
x509_att.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
x509_att.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
x509_att.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
x509_att.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
x509_att.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
x509_att.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
x509_att.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
x509_att.o: c:\mingw\include\string.h c:\mingw\include\strings.h
x509_att.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
x509_att.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
x509_att.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
x509_att.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
x509_att.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
x509_att.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
x509_att.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
x509_att.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
x509_att.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
x509_att.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
x509_att.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_att.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_att.c
x509_cmp.o: ../../e_os.h ../../include/openssl/asn1.h
x509_cmp.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509_cmp.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
x509_cmp.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
x509_cmp.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
x509_cmp.o: ../../include/openssl/err.h ../../include/openssl/evp.h
x509_cmp.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
x509_cmp.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
x509_cmp.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_cmp.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_cmp.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_cmp.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_cmp.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
x509_cmp.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
x509_cmp.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
x509_cmp.o: c:\mingw\include\ctype.h c:\mingw\include\dbt.h
x509_cmp.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
x509_cmp.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
x509_cmp.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
x509_cmp.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
x509_cmp.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
x509_cmp.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
x509_cmp.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
x509_cmp.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
x509_cmp.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
x509_cmp.o: c:\mingw\include\wctype.h c:\mingw\include\winbase.h
x509_cmp.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
x509_cmp.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
x509_cmp.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
x509_cmp.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
x509_cmp.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
x509_cmp.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
x509_cmp.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
x509_cmp.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_cmp.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_cmp.c
x509_d2.o: ../../e_os.h ../../include/openssl/asn1.h
x509_d2.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509_d2.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
x509_d2.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
x509_d2.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
x509_d2.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
x509_d2.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
x509_d2.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
x509_d2.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pkcs7.h
x509_d2.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
x509_d2.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
x509_d2.o: ../../include/openssl/x509.h ../../include/openssl/x509_vfy.h
x509_d2.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
x509_d2.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
x509_d2.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
x509_d2.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
x509_d2.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
x509_d2.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
x509_d2.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
x509_d2.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
x509_d2.o: c:\mingw\include\string.h c:\mingw\include\strings.h
x509_d2.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
x509_d2.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
x509_d2.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
x509_d2.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
x509_d2.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
x509_d2.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
x509_d2.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
x509_d2.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
x509_d2.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
x509_d2.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
x509_d2.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_d2.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_d2.c
x509_def.o: ../../e_os.h ../../include/openssl/asn1.h
x509_def.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509_def.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
x509_def.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
x509_def.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
x509_def.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
x509_def.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
x509_def.o: ../../include/openssl/opensslconf.h
x509_def.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_def.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_def.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_def.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_def.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
x509_def.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
x509_def.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
x509_def.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
x509_def.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
x509_def.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
x509_def.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
x509_def.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
x509_def.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
x509_def.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
x509_def.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
x509_def.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
x509_def.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
x509_def.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
x509_def.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
x509_def.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
x509_def.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
x509_def.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
x509_def.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
x509_def.o: c:\mingw\include\ws2tcpip.h
x509_def.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_def.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_def.c
x509_err.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
x509_err.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
x509_err.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
x509_err.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
x509_err.o: ../../include/openssl/err.h ../../include/openssl/evp.h
x509_err.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
x509_err.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
x509_err.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_err.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_err.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_err.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_err.o: ../../include/openssl/x509_vfy.h c:\mingw\include\_mingw.h
x509_err.o: c:\mingw\include\errno.h c:\mingw\include\msvcrtver.h
x509_err.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
x509_err.o: c:\mingw\include\stdlib.h c:\mingw\include\sys/types.h
x509_err.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
x509_err.o: c:\mingw\include\w32api.h
x509_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_err.c
x509_ext.o: ../../e_os.h ../../include/openssl/asn1.h
x509_ext.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509_ext.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
x509_ext.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
x509_ext.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
x509_ext.o: ../../include/openssl/err.h ../../include/openssl/evp.h
x509_ext.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
x509_ext.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
x509_ext.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_ext.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_ext.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_ext.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_ext.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
x509_ext.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
x509_ext.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
x509_ext.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
x509_ext.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
x509_ext.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
x509_ext.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
x509_ext.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
x509_ext.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
x509_ext.o: c:\mingw\include\string.h c:\mingw\include\strings.h
x509_ext.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
x509_ext.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
x509_ext.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
x509_ext.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
x509_ext.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
x509_ext.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
x509_ext.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
x509_ext.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
x509_ext.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
x509_ext.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
x509_ext.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_ext.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_ext.c
x509_lu.o: ../../e_os.h ../../include/openssl/asn1.h
x509_lu.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509_lu.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
x509_lu.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
x509_lu.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
x509_lu.o: ../../include/openssl/err.h ../../include/openssl/evp.h
x509_lu.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
x509_lu.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
x509_lu.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_lu.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_lu.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_lu.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_lu.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
x509_lu.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
x509_lu.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
x509_lu.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
x509_lu.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
x509_lu.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
x509_lu.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
x509_lu.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
x509_lu.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
x509_lu.o: c:\mingw\include\string.h c:\mingw\include\strings.h
x509_lu.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
x509_lu.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
x509_lu.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
x509_lu.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
x509_lu.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
x509_lu.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
x509_lu.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
x509_lu.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
x509_lu.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
x509_lu.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
x509_lu.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_lu.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_lu.c
x509_obj.o: ../../e_os.h ../../include/openssl/asn1.h
x509_obj.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509_obj.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
x509_obj.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
x509_obj.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
x509_obj.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
x509_obj.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
x509_obj.o: ../../include/openssl/opensslconf.h
x509_obj.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_obj.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_obj.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_obj.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_obj.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
x509_obj.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
x509_obj.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
x509_obj.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
x509_obj.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
x509_obj.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
x509_obj.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
x509_obj.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
x509_obj.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
x509_obj.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
x509_obj.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
x509_obj.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
x509_obj.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
x509_obj.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
x509_obj.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
x509_obj.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
x509_obj.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
x509_obj.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
x509_obj.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
x509_obj.o: c:\mingw\include\ws2tcpip.h
x509_obj.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_obj.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_obj.c
x509_r2x.o: ../../e_os.h ../../include/openssl/asn1.h
x509_r2x.o: ../../include/openssl/bio.h ../../include/openssl/bn.h
x509_r2x.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
x509_r2x.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
x509_r2x.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
x509_r2x.o: ../../include/openssl/err.h ../../include/openssl/evp.h
x509_r2x.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
x509_r2x.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
x509_r2x.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_r2x.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_r2x.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_r2x.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_r2x.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
x509_r2x.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
x509_r2x.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
x509_r2x.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
x509_r2x.o: c:\mingw\include\io.h c:\mingw\include\limits.h
x509_r2x.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
x509_r2x.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
x509_r2x.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
x509_r2x.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
x509_r2x.o: c:\mingw\include\string.h c:\mingw\include\strings.h
x509_r2x.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
x509_r2x.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
x509_r2x.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
x509_r2x.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
x509_r2x.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
x509_r2x.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
x509_r2x.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
x509_r2x.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
x509_r2x.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
x509_r2x.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
x509_r2x.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_r2x.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_r2x.c
x509_req.o: ../../e_os.h ../../include/openssl/asn1.h
x509_req.o: ../../include/openssl/asn1t.h ../../include/openssl/bio.h
x509_req.o: ../../include/openssl/bn.h ../../include/openssl/buffer.h
x509_req.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
x509_req.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
x509_req.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
x509_req.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
x509_req.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
x509_req.o: ../../include/openssl/opensslconf.h
x509_req.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_req.o: ../../include/openssl/pem.h ../../include/openssl/pem2.h
x509_req.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_req.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_req.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_req.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
x509_req.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
x509_req.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
x509_req.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
x509_req.o: c:\mingw\include\io.h c:\mingw\include\limits.h
x509_req.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
x509_req.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
x509_req.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
x509_req.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
x509_req.o: c:\mingw\include\string.h c:\mingw\include\strings.h
x509_req.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
x509_req.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
x509_req.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
x509_req.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
x509_req.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
x509_req.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
x509_req.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
x509_req.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
x509_req.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
x509_req.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
x509_req.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_req.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_req.c
x509_set.o: ../../e_os.h ../../include/openssl/asn1.h
x509_set.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509_set.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
x509_set.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
x509_set.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
x509_set.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
x509_set.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
x509_set.o: ../../include/openssl/opensslconf.h
x509_set.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_set.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_set.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_set.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_set.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
x509_set.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
x509_set.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
x509_set.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
x509_set.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
x509_set.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
x509_set.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
x509_set.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
x509_set.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
x509_set.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
x509_set.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
x509_set.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
x509_set.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
x509_set.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
x509_set.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
x509_set.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
x509_set.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
x509_set.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
x509_set.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
x509_set.o: c:\mingw\include\ws2tcpip.h
x509_set.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_set.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_set.c
x509_trs.o: ../../e_os.h ../../include/openssl/asn1.h
x509_trs.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509_trs.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
x509_trs.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
x509_trs.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
x509_trs.o: ../../include/openssl/err.h ../../include/openssl/evp.h
x509_trs.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
x509_trs.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
x509_trs.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_trs.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_trs.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_trs.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_trs.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
x509_trs.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
x509_trs.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
x509_trs.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
x509_trs.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
x509_trs.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
x509_trs.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
x509_trs.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
x509_trs.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
x509_trs.o: c:\mingw\include\string.h c:\mingw\include\strings.h
x509_trs.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
x509_trs.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
x509_trs.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
x509_trs.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
x509_trs.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
x509_trs.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
x509_trs.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
x509_trs.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
x509_trs.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
x509_trs.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
x509_trs.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_trs.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_trs.c
x509_txt.o: ../../e_os.h ../../include/openssl/asn1.h
x509_txt.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509_txt.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
x509_txt.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
x509_txt.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
x509_txt.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
x509_txt.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
x509_txt.o: ../../include/openssl/opensslconf.h
x509_txt.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_txt.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_txt.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_txt.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_txt.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
x509_txt.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
x509_txt.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
x509_txt.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
x509_txt.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
x509_txt.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
x509_txt.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
x509_txt.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
x509_txt.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
x509_txt.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
x509_txt.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
x509_txt.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
x509_txt.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
x509_txt.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
x509_txt.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
x509_txt.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
x509_txt.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
x509_txt.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
x509_txt.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
x509_txt.o: c:\mingw\include\ws2tcpip.h
x509_txt.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_txt.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_txt.c
x509_v3.o: ../../e_os.h ../../include/openssl/asn1.h
x509_v3.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509_v3.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
x509_v3.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
x509_v3.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
x509_v3.o: ../../include/openssl/err.h ../../include/openssl/evp.h
x509_v3.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
x509_v3.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
x509_v3.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_v3.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_v3.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_v3.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_v3.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
x509_v3.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
x509_v3.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
x509_v3.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
x509_v3.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
x509_v3.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
x509_v3.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
x509_v3.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
x509_v3.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
x509_v3.o: c:\mingw\include\string.h c:\mingw\include\strings.h
x509_v3.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
x509_v3.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
x509_v3.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
x509_v3.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
x509_v3.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
x509_v3.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
x509_v3.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
x509_v3.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
x509_v3.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
x509_v3.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
x509_v3.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_v3.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509_v3.c
x509_vfy.o: ../../e_os.h ../../include/openssl/asn1.h
x509_vfy.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509_vfy.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
x509_vfy.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
x509_vfy.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
x509_vfy.o: ../../include/openssl/err.h ../../include/openssl/evp.h
x509_vfy.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
x509_vfy.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
x509_vfy.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_vfy.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_vfy.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_vfy.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_vfy.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
x509_vfy.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
x509_vfy.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
x509_vfy.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
x509_vfy.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
x509_vfy.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
x509_vfy.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
x509_vfy.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
x509_vfy.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
x509_vfy.o: c:\mingw\include\string.h c:\mingw\include\strings.h
x509_vfy.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
x509_vfy.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
x509_vfy.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
x509_vfy.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
x509_vfy.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
x509_vfy.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
x509_vfy.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
x509_vfy.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
x509_vfy.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
x509_vfy.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
x509_vfy.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_vfy.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h vpm_int.h
x509_vfy.o: x509_vfy.c
x509_vpm.o: ../../e_os.h ../../include/openssl/asn1.h
x509_vpm.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509_vpm.o: ../../include/openssl/conf.h ../../include/openssl/crypto.h
x509_vpm.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
x509_vpm.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
x509_vpm.o: ../../include/openssl/err.h ../../include/openssl/evp.h
x509_vpm.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
x509_vpm.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
x509_vpm.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509_vpm.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509_vpm.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509_vpm.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509_vpm.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
x509_vpm.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
x509_vpm.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
x509_vpm.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
x509_vpm.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
x509_vpm.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
x509_vpm.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
x509_vpm.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
x509_vpm.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
x509_vpm.o: c:\mingw\include\string.h c:\mingw\include\strings.h
x509_vpm.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
x509_vpm.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
x509_vpm.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
x509_vpm.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
x509_vpm.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
x509_vpm.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
x509_vpm.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
x509_vpm.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
x509_vpm.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
x509_vpm.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
x509_vpm.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509_vpm.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h vpm_int.h
x509_vpm.o: x509_vpm.c
x509cset.o: ../../e_os.h ../../include/openssl/asn1.h
x509cset.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509cset.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
x509cset.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
x509cset.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
x509cset.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
x509cset.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
x509cset.o: ../../include/openssl/opensslconf.h
x509cset.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509cset.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509cset.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509cset.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509cset.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
x509cset.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
x509cset.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
x509cset.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
x509cset.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
x509cset.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
x509cset.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
x509cset.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
x509cset.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
x509cset.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
x509cset.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
x509cset.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
x509cset.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
x509cset.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
x509cset.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
x509cset.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
x509cset.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
x509cset.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
x509cset.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
x509cset.o: c:\mingw\include\ws2tcpip.h
x509cset.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509cset.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509cset.c
x509name.o: ../../e_os.h ../../include/openssl/asn1.h
x509name.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509name.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
x509name.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
x509name.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
x509name.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
x509name.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
x509name.o: ../../include/openssl/opensslconf.h
x509name.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509name.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509name.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509name.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509name.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
x509name.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
x509name.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
x509name.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
x509name.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
x509name.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
x509name.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
x509name.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
x509name.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
x509name.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
x509name.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
x509name.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
x509name.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
x509name.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
x509name.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
x509name.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
x509name.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
x509name.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
x509name.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
x509name.o: c:\mingw\include\ws2tcpip.h
x509name.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509name.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509name.c
x509rset.o: ../../e_os.h ../../include/openssl/asn1.h
x509rset.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509rset.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
x509rset.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
x509rset.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
x509rset.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
x509rset.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
x509rset.o: ../../include/openssl/opensslconf.h
x509rset.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509rset.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509rset.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509rset.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509rset.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
x509rset.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
x509rset.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
x509rset.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
x509rset.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
x509rset.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
x509rset.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
x509rset.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
x509rset.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
x509rset.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
x509rset.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
x509rset.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
x509rset.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
x509rset.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
x509rset.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
x509rset.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
x509rset.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
x509rset.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
x509rset.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
x509rset.o: c:\mingw\include\ws2tcpip.h
x509rset.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509rset.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509rset.c
x509spki.o: ../../e_os.h ../../include/openssl/asn1.h
x509spki.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509spki.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
x509spki.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
x509spki.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
x509spki.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
x509spki.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
x509spki.o: ../../include/openssl/opensslconf.h
x509spki.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509spki.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509spki.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509spki.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509spki.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
x509spki.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
x509spki.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
x509spki.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
x509spki.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
x509spki.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
x509spki.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
x509spki.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
x509spki.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
x509spki.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
x509spki.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
x509spki.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
x509spki.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
x509spki.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
x509spki.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
x509spki.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
x509spki.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
x509spki.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
x509spki.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
x509spki.o: c:\mingw\include\ws2tcpip.h
x509spki.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509spki.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509spki.c
x509type.o: ../../e_os.h ../../include/openssl/asn1.h
x509type.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
x509type.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
x509type.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
x509type.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
x509type.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
x509type.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
x509type.o: ../../include/openssl/opensslconf.h
x509type.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
x509type.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
x509type.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x509type.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x509type.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
x509type.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
x509type.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
x509type.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
x509type.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
x509type.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
x509type.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
x509type.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
x509type.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
x509type.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
x509type.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
x509type.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
x509type.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
x509type.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
x509type.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
x509type.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
x509type.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
x509type.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
x509type.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
x509type.o: c:\mingw\include\ws2tcpip.h
x509type.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x509type.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x509type.c
x_all.o: ../../e_os.h ../../include/openssl/asn1.h ../../include/openssl/bio.h
x_all.o: ../../include/openssl/buffer.h ../../include/openssl/conf.h
x_all.o: ../../include/openssl/crypto.h ../../include/openssl/dsa.h
x_all.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
x_all.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
x_all.o: ../../include/openssl/err.h ../../include/openssl/evp.h
x_all.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
x_all.o: ../../include/openssl/objects.h ../../include/openssl/ocsp.h
x_all.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
x_all.o: ../../include/openssl/ossl_typ.h ../../include/openssl/pkcs7.h
x_all.o: ../../include/openssl/rsa.h ../../include/openssl/safestack.h
x_all.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
x_all.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
x_all.o: ../../include/openssl/x509_vfy.h ../../include/openssl/x509v3.h
x_all.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
x_all.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
x_all.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
x_all.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
x_all.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
x_all.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
x_all.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
x_all.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
x_all.o: c:\mingw\include\string.h c:\mingw\include\strings.h
x_all.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
x_all.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
x_all.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
x_all.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
x_all.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
x_all.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
x_all.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
x_all.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
x_all.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
x_all.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
x_all.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
x_all.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h x_all.c
