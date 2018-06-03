#
# crypto/ec/Makefile
#

DIR=	ec
TOP=	../..
CC=	cc
INCLUDES= -I.. -I$(TOP) -I../../include
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)
ASFLAGS= $(INCLUDES) $(ASFLAG)
AFLAGS= $(ASFLAGS)

GENERAL=Makefile
TEST=ectest.c
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC=	ec_lib.c ecp_smpl.c ecp_mont.c ecp_nist.c ec_cvt.c ec_mult.c\
	ec_err.c ec_curve.c ec_check.c ec_print.c ec_asn1.c ec_key.c\
	ec2_smpl.c ec2_mult.c ec_ameth.c ec_pmeth.c eck_prn.c \
	ecp_nistp224.c ecp_nistp256.c ecp_nistp521.c ecp_nistputil.c \
	ecp_oct.c ec2_oct.c ec_oct.c

LIBOBJ=	ec_lib.o ecp_smpl.o ecp_mont.o ecp_nist.o ec_cvt.o ec_mult.o\
	ec_err.o ec_curve.o ec_check.o ec_print.o ec_asn1.o ec_key.o\
	ec2_smpl.o ec2_mult.o ec_ameth.o ec_pmeth.o eck_prn.o \
	ecp_nistp224.o ecp_nistp256.o ecp_nistp521.o ecp_nistputil.o \
	ecp_oct.o ec2_oct.o ec_oct.o $(EC_ASM)

SRC= $(LIBSRC)

EXHEADER= ec.h
HEADER=	ec_lcl.h $(EXHEADER)

ALL=    $(GENERAL) $(SRC) $(HEADER)

top:
	(cd ../..; $(MAKE) DIRS=crypto SDIRS=$(DIR) sub_all)

all:	lib

lib:	$(LIBOBJ)
	$(AR) $(LIB) $(LIBOBJ)
	$(RANLIB) $(LIB) || echo Never mind.
	@touch lib

ecp_nistz256-x86_64.s: asm/ecp_nistz256-x86_64.pl
	$(PERL) asm/ecp_nistz256-x86_64.pl $(PERLASM_SCHEME) > $@

ecp_nistz256-avx2.s:   asm/ecp_nistz256-avx2.pl
	$(PERL) asm/ecp_nistz256-avx2.pl $(PERLASM_SCHEME) > $@

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
	rm -f *.s *.o */*.o *.obj lib tags core .pure .nfs* *.old *.bak fluff

# DO NOT DELETE THIS LINE -- make depend depends on it.

ec2_mult.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ec2_mult.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ec2_mult.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ec2_mult.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ec2_mult.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ec2_mult.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec2_mult.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ec2_mult.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ec2_mult.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ec2_mult.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ec2_mult.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ec2_mult.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ec2_mult.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ec2_mult.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec2_mult.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec2_mult.c ec_lcl.h
ec2_oct.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ec2_oct.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ec2_oct.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ec2_oct.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ec2_oct.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ec2_oct.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec2_oct.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ec2_oct.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ec2_oct.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ec2_oct.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ec2_oct.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ec2_oct.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ec2_oct.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ec2_oct.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec2_oct.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec2_oct.c ec_lcl.h
ec2_smpl.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ec2_smpl.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ec2_smpl.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ec2_smpl.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ec2_smpl.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ec2_smpl.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec2_smpl.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ec2_smpl.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ec2_smpl.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ec2_smpl.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ec2_smpl.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ec2_smpl.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ec2_smpl.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ec2_smpl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec2_smpl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec2_smpl.c ec_lcl.h
ec_ameth.o: ../../e_os.h ../../include/openssl/asn1.h
ec_ameth.o: ../../include/openssl/asn1t.h ../../include/openssl/bio.h
ec_ameth.o: ../../include/openssl/bn.h ../../include/openssl/buffer.h
ec_ameth.o: ../../include/openssl/cms.h ../../include/openssl/crypto.h
ec_ameth.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ec_ameth.o: ../../include/openssl/ecdh.h ../../include/openssl/ecdsa.h
ec_ameth.o: ../../include/openssl/err.h ../../include/openssl/evp.h
ec_ameth.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
ec_ameth.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
ec_ameth.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec_ameth.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
ec_ameth.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
ec_ameth.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
ec_ameth.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
ec_ameth.o: ../../ms/uplink.h ../asn1/asn1_locl.h ../cryptlib.h
ec_ameth.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
ec_ameth.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
ec_ameth.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
ec_ameth.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
ec_ameth.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
ec_ameth.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
ec_ameth.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
ec_ameth.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
ec_ameth.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
ec_ameth.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
ec_ameth.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
ec_ameth.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
ec_ameth.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
ec_ameth.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
ec_ameth.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
ec_ameth.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
ec_ameth.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
ec_ameth.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
ec_ameth.o: c:\mingw\include\ws2tcpip.h
ec_ameth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec_ameth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_ameth.c ec_lcl.h
ec_asn1.o: ../../include/openssl/asn1.h ../../include/openssl/asn1t.h
ec_asn1.o: ../../include/openssl/bio.h ../../include/openssl/bn.h
ec_asn1.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
ec_asn1.o: ../../include/openssl/ec.h ../../include/openssl/err.h
ec_asn1.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
ec_asn1.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
ec_asn1.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec_asn1.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ec_asn1.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ec_asn1.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ec_asn1.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ec_asn1.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ec_asn1.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ec_asn1.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ec_asn1.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ec_asn1.o: c:\mingw\include\wchar.h
ec_asn1.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec_asn1.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_asn1.c ec_lcl.h
ec_check.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ec_check.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ec_check.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ec_check.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ec_check.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ec_check.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec_check.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ec_check.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ec_check.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ec_check.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ec_check.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ec_check.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ec_check.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ec_check.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec_check.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_check.c ec_lcl.h
ec_curve.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ec_curve.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ec_curve.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ec_curve.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ec_curve.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ec_curve.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec_curve.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ec_curve.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ec_curve.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ec_curve.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ec_curve.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ec_curve.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ec_curve.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ec_curve.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ec_curve.o: c:\mingw\include\wchar.h
ec_curve.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec_curve.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_curve.c ec_lcl.h
ec_cvt.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ec_cvt.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ec_cvt.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ec_cvt.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ec_cvt.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ec_cvt.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec_cvt.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ec_cvt.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ec_cvt.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ec_cvt.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ec_cvt.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ec_cvt.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ec_cvt.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ec_cvt.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec_cvt.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_cvt.c ec_lcl.h
ec_err.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ec_err.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
ec_err.o: ../../include/openssl/ec.h ../../include/openssl/err.h
ec_err.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
ec_err.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec_err.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ec_err.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ec_err.o: c:\mingw\include\errno.h c:\mingw\include\msvcrtver.h
ec_err.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
ec_err.o: c:\mingw\include\stdlib.h c:\mingw\include\sys/types.h
ec_err.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
ec_err.o: c:\mingw\include\w32api.h
ec_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_err.c
ec_key.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ec_key.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ec_key.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ec_key.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ec_key.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ec_key.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec_key.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ec_key.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ec_key.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ec_key.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ec_key.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ec_key.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ec_key.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ec_key.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ec_key.o: c:\mingw\include\wchar.h
ec_key.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec_key.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_key.c ec_lcl.h
ec_lib.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ec_lib.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ec_lib.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ec_lib.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ec_lib.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ec_lib.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec_lib.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ec_lib.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ec_lib.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ec_lib.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ec_lib.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ec_lib.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ec_lib.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ec_lib.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ec_lib.o: c:\mingw\include\wchar.h
ec_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_lcl.h ec_lib.c
ec_mult.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ec_mult.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ec_mult.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ec_mult.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ec_mult.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ec_mult.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec_mult.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ec_mult.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ec_mult.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ec_mult.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ec_mult.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ec_mult.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ec_mult.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ec_mult.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ec_mult.o: c:\mingw\include\wchar.h
ec_mult.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec_mult.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_lcl.h ec_mult.c
ec_oct.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ec_oct.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ec_oct.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ec_oct.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ec_oct.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ec_oct.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec_oct.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ec_oct.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ec_oct.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ec_oct.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ec_oct.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ec_oct.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ec_oct.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ec_oct.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ec_oct.o: c:\mingw\include\wchar.h
ec_oct.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec_oct.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_lcl.h ec_oct.c
ec_pmeth.o: ../../e_os.h ../../include/openssl/asn1.h
ec_pmeth.o: ../../include/openssl/asn1t.h ../../include/openssl/bio.h
ec_pmeth.o: ../../include/openssl/bn.h ../../include/openssl/buffer.h
ec_pmeth.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
ec_pmeth.o: ../../include/openssl/ec.h ../../include/openssl/ecdh.h
ec_pmeth.o: ../../include/openssl/ecdsa.h ../../include/openssl/err.h
ec_pmeth.o: ../../include/openssl/evp.h ../../include/openssl/lhash.h
ec_pmeth.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
ec_pmeth.o: ../../include/openssl/opensslconf.h
ec_pmeth.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec_pmeth.o: ../../include/openssl/pkcs7.h ../../include/openssl/safestack.h
ec_pmeth.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
ec_pmeth.o: ../../include/openssl/symhacks.h ../../include/openssl/x509.h
ec_pmeth.o: ../../include/openssl/x509_vfy.h ../../ms/applink.c
ec_pmeth.o: ../../ms/uplink.h ../cryptlib.h ../evp/evp_locl.h
ec_pmeth.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
ec_pmeth.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
ec_pmeth.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
ec_pmeth.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
ec_pmeth.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
ec_pmeth.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
ec_pmeth.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
ec_pmeth.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
ec_pmeth.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
ec_pmeth.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
ec_pmeth.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
ec_pmeth.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
ec_pmeth.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
ec_pmeth.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
ec_pmeth.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
ec_pmeth.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
ec_pmeth.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
ec_pmeth.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
ec_pmeth.o: c:\mingw\include\ws2tcpip.h
ec_pmeth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec_pmeth.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_lcl.h ec_pmeth.c
ec_print.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ec_print.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ec_print.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ec_print.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ec_print.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ec_print.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ec_print.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ec_print.o: c:\mingw\include\limits.h c:\mingw\include\msvcrtver.h
ec_print.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
ec_print.o: c:\mingw\include\stdlib.h c:\mingw\include\sys/types.h
ec_print.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
ec_print.o: c:\mingw\include\w32api.h
ec_print.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ec_print.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_lcl.h ec_print.c
eck_prn.o: ../../e_os.h ../../include/openssl/asn1.h
eck_prn.o: ../../include/openssl/bio.h ../../include/openssl/bn.h
eck_prn.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
eck_prn.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
eck_prn.o: ../../include/openssl/err.h ../../include/openssl/evp.h
eck_prn.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
eck_prn.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
eck_prn.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
eck_prn.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
eck_prn.o: ../../include/openssl/symhacks.h ../../ms/applink.c
eck_prn.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
eck_prn.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
eck_prn.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
eck_prn.o: c:\mingw\include\io.h c:\mingw\include\limits.h
eck_prn.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
eck_prn.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
eck_prn.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
eck_prn.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
eck_prn.o: c:\mingw\include\string.h c:\mingw\include\strings.h
eck_prn.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
eck_prn.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
eck_prn.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
eck_prn.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
eck_prn.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
eck_prn.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
eck_prn.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
eck_prn.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
eck_prn.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
eck_prn.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
eck_prn.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
eck_prn.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h eck_prn.c
ecp_mont.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ecp_mont.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ecp_mont.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ecp_mont.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ecp_mont.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ecp_mont.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ecp_mont.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ecp_mont.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ecp_mont.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ecp_mont.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ecp_mont.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ecp_mont.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ecp_mont.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ecp_mont.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ecp_mont.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_lcl.h ecp_mont.c
ecp_nist.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ecp_nist.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ecp_nist.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ecp_nist.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ecp_nist.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ecp_nist.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ecp_nist.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ecp_nist.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ecp_nist.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ecp_nist.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ecp_nist.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ecp_nist.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ecp_nist.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ecp_nist.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ecp_nist.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_lcl.h ecp_nist.c
ecp_nistp224.o: ../../include/openssl/opensslconf.h ecp_nistp224.c
ecp_nistp256.o: ../../include/openssl/opensslconf.h ecp_nistp256.c
ecp_nistp521.o: ../../include/openssl/opensslconf.h ecp_nistp521.c
ecp_nistputil.o: ../../include/openssl/opensslconf.h ecp_nistputil.c
ecp_oct.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ecp_oct.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ecp_oct.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ecp_oct.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ecp_oct.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ecp_oct.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ecp_oct.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ecp_oct.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ecp_oct.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ecp_oct.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ecp_oct.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ecp_oct.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ecp_oct.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ecp_oct.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ecp_oct.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_lcl.h ecp_oct.c
ecp_smpl.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
ecp_smpl.o: ../../include/openssl/bn.h ../../include/openssl/crypto.h
ecp_smpl.o: ../../include/openssl/e_os2.h ../../include/openssl/ec.h
ecp_smpl.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
ecp_smpl.o: ../../include/openssl/obj_mac.h ../../include/openssl/opensslconf.h
ecp_smpl.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
ecp_smpl.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
ecp_smpl.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ecp_smpl.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
ecp_smpl.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
ecp_smpl.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ecp_smpl.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ecp_smpl.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ecp_smpl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ecp_smpl.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ec_lcl.h ecp_smpl.c
