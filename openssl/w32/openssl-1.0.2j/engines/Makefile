#
# OpenSSL/engines/Makefile
#

DIR=	engines
TOP=	..
CC=	cc
INCLUDES= -I../include
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r
ENGDIRS= ccgost

RECURSIVE_MAKE=	[ -z "$(ENGDIRS)" ] || for i in $(ENGDIRS) ; do \
		    (cd $$i && echo "making $$target in $(DIR)/$$i..." && \
		    $(MAKE) -e TOP=../.. DIR=$$i $$target ) || exit 1; \
		done;

PEX_LIBS=
EX_LIBS=

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile engines.com install.com engine_vector.mar
TEST=
APPS=

LIB=$(TOP)/libcrypto.a
LIBNAMES= 4758cca aep atalla cswift gmp chil nuron sureware ubsec padlock capi

LIBSRC=	e_4758cca.c \
	e_aep.c \
	e_atalla.c \
	e_cswift.c \
	e_gmp.c \
	e_chil.c \
	e_nuron.c \
	e_sureware.c \
	e_ubsec.c \
	e_padlock.c \
	e_capi.c
LIBOBJ= e_4758cca.o \
	e_aep.o \
	e_atalla.o \
	e_cswift.o \
	e_gmp.o \
	e_chil.o \
	e_nuron.o \
	e_sureware.o \
	e_ubsec.o \
	e_padlock.o \
	e_capi.o

SRC= $(LIBSRC)

EXHEADER= 
HEADER=	e_4758cca_err.c e_4758cca_err.h \
	e_aep_err.c e_aep_err.h \
	e_atalla_err.c e_atalla_err.h \
	e_cswift_err.c e_cswift_err.h \
	e_gmp_err.c e_gmp_err.h \
	e_chil_err.c e_chil_err.h \
	e_nuron_err.c e_nuron_err.h \
	e_sureware_err.c e_sureware_err.h \
	e_ubsec_err.c e_ubsec_err.h \
	e_capi_err.c e_capi_err.h

ALL=    $(GENERAL) $(SRC) $(HEADER)

top:
	(cd ..; $(MAKE) DIRS=$(DIR) all)

all:	lib subdirs

lib:	$(LIBOBJ)
	@if [ -n "$(SHARED_LIBS)" ]; then \
		set -e; \
		for l in $(LIBNAMES); do \
			$(MAKE) -f ../Makefile.shared -e \
				LIBNAME=$$l LIBEXTRAS=e_$$l.o \
				LIBDEPS='-L.. -lcrypto $(EX_LIBS)' \
				link_o.$(SHLIB_TARGET); \
		done; \
	else \
		$(AR) $(LIB) $(LIBOBJ); \
		$(RANLIB) $(LIB) || echo Never mind.; \
	fi; \
	touch lib

subdirs:
	echo $(EDIRS)
	@target=all; $(RECURSIVE_MAKE)

files:
	$(PERL) $(TOP)/util/files.pl Makefile >> $(TOP)/MINFO
	@target=files; $(RECURSIVE_MAKE)

links:
	@target=links; $(RECURSIVE_MAKE)

# XXXXX This currently only works on systems that use .so as suffix
# for shared libraries as well as for Cygwin which uses the
# dlfcn_name_converter and therefore stores the engines with .so suffix, too.
# XXXXX This was extended to HP-UX dl targets, which use .sl suffix.
# XXXXX This was extended to mingw targets, which use eay32.dll suffix without lib as prefix.
install:
	@[ -n "$(INSTALLTOP)" ] # should be set by top Makefile...
	@if [ -n "$(SHARED_LIBS)" ]; then \
		set -e; \
		$(PERL) $(TOP)/util/mkdir-p.pl $(INSTALL_PREFIX)$(INSTALLTOP)/$(LIBDIR)/engines; \
		for l in $(LIBNAMES); do \
			( echo installing $$l; \
			  pfx=lib; \
			  if expr "$(PLATFORM)" : "Cygwin" >/dev/null; then \
				sfx=".so"; \
				cp cyg$$l.dll $(INSTALL_PREFIX)$(INSTALLTOP)/$(LIBDIR)/engines/$$pfx$$l$$sfx.new; \
			  else \
				case "$(CFLAGS)" in \
				*DSO_BEOS*)	sfx=".so";;	\
				*DSO_DLFCN*)	sfx=`expr "$(SHLIB_EXT)" : '.*\(\.[a-z][a-z]*\)' \| ".so"`;;	\
				*DSO_DL*)	sfx=".sl";;	\
				*DSO_WIN32*)	sfx="eay32.dll"; pfx=;;	\
				*)		sfx=".bad";;	\
				esac; \
				cp $$pfx$$l$$sfx $(INSTALL_PREFIX)$(INSTALLTOP)/$(LIBDIR)/engines/$$pfx$$l$$sfx.new; \
			  fi; \
			  chmod 555 $(INSTALL_PREFIX)$(INSTALLTOP)/$(LIBDIR)/engines/$$pfx$$l$$sfx.new; \
			  mv -f $(INSTALL_PREFIX)$(INSTALLTOP)/$(LIBDIR)/engines/$$pfx$$l$$sfx.new $(INSTALL_PREFIX)$(INSTALLTOP)/$(LIBDIR)/engines/$$pfx$$l$$sfx ); \
		done; \
	fi
	@target=install; $(RECURSIVE_MAKE)

tags:
	ctags $(SRC)

errors:
	set -e; for l in $(LIBNAMES); do \
		$(PERL) ../util/mkerr.pl -conf e_$$l.ec \
			-nostatic -staticloader -write e_$$l.c; \
	done
	(cd ccgost; $(MAKE) PERL=$(PERL) errors)

tests:

lint:
	lint -DLINT $(INCLUDES) $(SRC)>fluff
	@target=lint; $(RECURSIVE_MAKE)

update: local_depend
	@if [ -z "$(THIS)" ]; then $(MAKE) -f $(TOP)/Makefile reflect THIS=$@; fi
	@[ -z "$(THIS)" ] || (set -e; target=update; $(RECURSIVE_MAKE) )

depend: local_depend
	@if [ -z "$(THIS)" ]; then $(MAKE) -f $(TOP)/Makefile reflect THIS=$@; fi
	@[ -z "$(THIS)" ] || (set -e; target=depend; $(RECURSIVE_MAKE) )
local_depend:
	@[ -z "$(THIS)" ] || $(MAKEDEPEND) -- $(CFLAG) $(INCLUDES) $(DEPFLAG) -- $(PROGS) $(LIBSRC)

dclean:
	$(PERL) -pe 'if (/^# DO NOT DELETE THIS LINE/) {print; exit(0);}' $(MAKEFILE) >Makefile.new
	mv -f Makefile.new $(MAKEFILE)
	@target=dclean; $(RECURSIVE_MAKE)

clean:
	rm -f *.o *.obj lib tags core .pure .nfs* *.old *.bak fluff
	@target=clean; $(RECURSIVE_MAKE)

# DO NOT DELETE THIS LINE -- make depend depends on it.

e_4758cca.o: ../include/openssl/asn1.h ../include/openssl/bio.h
e_4758cca.o: ../include/openssl/bn.h ../include/openssl/buffer.h
e_4758cca.o: ../include/openssl/crypto.h ../include/openssl/dso.h
e_4758cca.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
e_4758cca.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
e_4758cca.o: ../include/openssl/engine.h ../include/openssl/err.h
e_4758cca.o: ../include/openssl/evp.h ../include/openssl/lhash.h
e_4758cca.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
e_4758cca.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
e_4758cca.o: ../include/openssl/ossl_typ.h ../include/openssl/pkcs7.h
e_4758cca.o: ../include/openssl/rand.h ../include/openssl/rsa.h
e_4758cca.o: ../include/openssl/safestack.h ../include/openssl/sha.h
e_4758cca.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
e_4758cca.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h
e_4758cca.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
e_4758cca.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
e_4758cca.o: c:\mingw\include\limits.h c:\mingw\include\msvcrtver.h
e_4758cca.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
e_4758cca.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
e_4758cca.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
e_4758cca.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
e_4758cca.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
e_4758cca.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
e_4758cca.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
e_4758cca.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
e_4758cca.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
e_4758cca.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
e_4758cca.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
e_4758cca.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
e_4758cca.o: c:\mingw\include\winver.h
e_4758cca.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
e_4758cca.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h e_4758cca.c
e_4758cca.o: e_4758cca_err.c e_4758cca_err.h vendor_defns/hw_4758_cca.h
e_aep.o: ../include/openssl/asn1.h ../include/openssl/bio.h
e_aep.o: ../include/openssl/bn.h ../include/openssl/buffer.h
e_aep.o: ../include/openssl/crypto.h ../include/openssl/dh.h
e_aep.o: ../include/openssl/dsa.h ../include/openssl/dso.h
e_aep.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
e_aep.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
e_aep.o: ../include/openssl/engine.h ../include/openssl/err.h
e_aep.o: ../include/openssl/evp.h ../include/openssl/lhash.h
e_aep.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
e_aep.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
e_aep.o: ../include/openssl/ossl_typ.h ../include/openssl/pkcs7.h
e_aep.o: ../include/openssl/rsa.h ../include/openssl/safestack.h
e_aep.o: ../include/openssl/sha.h ../include/openssl/stack.h
e_aep.o: ../include/openssl/symhacks.h ../include/openssl/x509.h
e_aep.o: ../include/openssl/x509_vfy.h c:\mingw\include\_mingw.h
e_aep.o: c:\mingw\include\errno.h c:\mingw\include\getopt.h
e_aep.o: c:\mingw\include\io.h c:\mingw\include\limits.h
e_aep.o: c:\mingw\include\msvcrtver.h c:\mingw\include\process.h
e_aep.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
e_aep.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
e_aep.o: c:\mingw\include\string.h c:\mingw\include\strings.h
e_aep.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
e_aep.o: c:\mingw\include\time.h c:\mingw\include\unistd.h
e_aep.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
e_aep.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
e_aep.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h e_aep.c e_aep_err.c
e_aep.o: e_aep_err.h vendor_defns/aep.h
e_atalla.o: ../include/openssl/asn1.h ../include/openssl/bio.h
e_atalla.o: ../include/openssl/bn.h ../include/openssl/buffer.h
e_atalla.o: ../include/openssl/crypto.h ../include/openssl/dh.h
e_atalla.o: ../include/openssl/dsa.h ../include/openssl/dso.h
e_atalla.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
e_atalla.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
e_atalla.o: ../include/openssl/engine.h ../include/openssl/err.h
e_atalla.o: ../include/openssl/evp.h ../include/openssl/lhash.h
e_atalla.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
e_atalla.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
e_atalla.o: ../include/openssl/ossl_typ.h ../include/openssl/pkcs7.h
e_atalla.o: ../include/openssl/rsa.h ../include/openssl/safestack.h
e_atalla.o: ../include/openssl/sha.h ../include/openssl/stack.h
e_atalla.o: ../include/openssl/symhacks.h ../include/openssl/x509.h
e_atalla.o: ../include/openssl/x509_vfy.h c:\mingw\include\_mingw.h
e_atalla.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
e_atalla.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
e_atalla.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
e_atalla.o: c:\mingw\include\string.h c:\mingw\include\strings.h
e_atalla.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
e_atalla.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
e_atalla.o: c:\mingw\include\wchar.h
e_atalla.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
e_atalla.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h e_atalla.c
e_atalla.o: e_atalla_err.c e_atalla_err.h vendor_defns/atalla.h
e_capi.o: ../include/openssl/asn1.h ../include/openssl/bio.h
e_capi.o: ../include/openssl/bn.h ../include/openssl/buffer.h
e_capi.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
e_capi.o: ../include/openssl/ec.h ../include/openssl/ecdh.h
e_capi.o: ../include/openssl/ecdsa.h ../include/openssl/engine.h
e_capi.o: ../include/openssl/evp.h ../include/openssl/lhash.h
e_capi.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
e_capi.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
e_capi.o: ../include/openssl/ossl_typ.h ../include/openssl/pkcs7.h
e_capi.o: ../include/openssl/rsa.h ../include/openssl/safestack.h
e_capi.o: ../include/openssl/sha.h ../include/openssl/stack.h
e_capi.o: ../include/openssl/symhacks.h ../include/openssl/x509.h
e_capi.o: ../include/openssl/x509_vfy.h c:\mingw\include\_mingw.h
e_capi.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
e_capi.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
e_capi.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
e_capi.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
e_capi.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
e_capi.o: c:\mingw\include\string.h c:\mingw\include\strings.h
e_capi.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
e_capi.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
e_capi.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
e_capi.o: c:\mingw\include\wincon.h c:\mingw\include\wincrypt.h
e_capi.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
e_capi.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
e_capi.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
e_capi.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
e_capi.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
e_capi.o: c:\mingw\include\winver.h
e_capi.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
e_capi.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h e_capi.c
e_chil.o: ../include/openssl/asn1.h ../include/openssl/bio.h
e_chil.o: ../include/openssl/bn.h ../include/openssl/buffer.h
e_chil.o: ../include/openssl/crypto.h ../include/openssl/dh.h
e_chil.o: ../include/openssl/dso.h ../include/openssl/e_os2.h
e_chil.o: ../include/openssl/ec.h ../include/openssl/ecdh.h
e_chil.o: ../include/openssl/ecdsa.h ../include/openssl/engine.h
e_chil.o: ../include/openssl/err.h ../include/openssl/evp.h
e_chil.o: ../include/openssl/lhash.h ../include/openssl/obj_mac.h
e_chil.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
e_chil.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
e_chil.o: ../include/openssl/pem.h ../include/openssl/pem2.h
e_chil.o: ../include/openssl/pkcs7.h ../include/openssl/rand.h
e_chil.o: ../include/openssl/rsa.h ../include/openssl/safestack.h
e_chil.o: ../include/openssl/sha.h ../include/openssl/stack.h
e_chil.o: ../include/openssl/symhacks.h ../include/openssl/ui.h
e_chil.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h
e_chil.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
e_chil.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
e_chil.o: c:\mingw\include\limits.h c:\mingw\include\msvcrtver.h
e_chil.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
e_chil.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
e_chil.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
e_chil.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
e_chil.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
e_chil.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
e_chil.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
e_chil.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
e_chil.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
e_chil.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
e_chil.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
e_chil.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
e_chil.o: c:\mingw\include\winver.h
e_chil.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
e_chil.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h e_chil.c e_chil_err.c
e_chil.o: e_chil_err.h vendor_defns/hwcryptohook.h
e_cswift.o: ../include/openssl/asn1.h ../include/openssl/bio.h
e_cswift.o: ../include/openssl/bn.h ../include/openssl/buffer.h
e_cswift.o: ../include/openssl/crypto.h ../include/openssl/dh.h
e_cswift.o: ../include/openssl/dsa.h ../include/openssl/dso.h
e_cswift.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
e_cswift.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
e_cswift.o: ../include/openssl/engine.h ../include/openssl/err.h
e_cswift.o: ../include/openssl/evp.h ../include/openssl/lhash.h
e_cswift.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
e_cswift.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
e_cswift.o: ../include/openssl/ossl_typ.h ../include/openssl/pkcs7.h
e_cswift.o: ../include/openssl/rand.h ../include/openssl/rsa.h
e_cswift.o: ../include/openssl/safestack.h ../include/openssl/sha.h
e_cswift.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
e_cswift.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h
e_cswift.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
e_cswift.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
e_cswift.o: c:\mingw\include\limits.h c:\mingw\include\msvcrtver.h
e_cswift.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
e_cswift.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
e_cswift.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
e_cswift.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
e_cswift.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
e_cswift.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
e_cswift.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
e_cswift.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
e_cswift.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
e_cswift.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
e_cswift.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
e_cswift.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
e_cswift.o: c:\mingw\include\winver.h
e_cswift.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
e_cswift.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h e_cswift.c
e_cswift.o: e_cswift_err.c e_cswift_err.h vendor_defns/cswift.h
e_gmp.o: ../include/openssl/asn1.h ../include/openssl/bio.h
e_gmp.o: ../include/openssl/bn.h ../include/openssl/buffer.h
e_gmp.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
e_gmp.o: ../include/openssl/ec.h ../include/openssl/ecdh.h
e_gmp.o: ../include/openssl/ecdsa.h ../include/openssl/engine.h
e_gmp.o: ../include/openssl/evp.h ../include/openssl/lhash.h
e_gmp.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
e_gmp.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
e_gmp.o: ../include/openssl/ossl_typ.h ../include/openssl/pkcs7.h
e_gmp.o: ../include/openssl/rsa.h ../include/openssl/safestack.h
e_gmp.o: ../include/openssl/sha.h ../include/openssl/stack.h
e_gmp.o: ../include/openssl/symhacks.h ../include/openssl/x509.h
e_gmp.o: ../include/openssl/x509_vfy.h c:\mingw\include\_mingw.h
e_gmp.o: c:\mingw\include\limits.h c:\mingw\include\msvcrtver.h
e_gmp.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
e_gmp.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
e_gmp.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
e_gmp.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
e_gmp.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
e_gmp.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
e_gmp.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h e_gmp.c
e_nuron.o: ../include/openssl/asn1.h ../include/openssl/bio.h
e_nuron.o: ../include/openssl/bn.h ../include/openssl/buffer.h
e_nuron.o: ../include/openssl/crypto.h ../include/openssl/dh.h
e_nuron.o: ../include/openssl/dsa.h ../include/openssl/dso.h
e_nuron.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
e_nuron.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
e_nuron.o: ../include/openssl/engine.h ../include/openssl/err.h
e_nuron.o: ../include/openssl/evp.h ../include/openssl/lhash.h
e_nuron.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
e_nuron.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
e_nuron.o: ../include/openssl/ossl_typ.h ../include/openssl/pkcs7.h
e_nuron.o: ../include/openssl/rsa.h ../include/openssl/safestack.h
e_nuron.o: ../include/openssl/sha.h ../include/openssl/stack.h
e_nuron.o: ../include/openssl/symhacks.h ../include/openssl/x509.h
e_nuron.o: ../include/openssl/x509_vfy.h c:\mingw\include\_mingw.h
e_nuron.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
e_nuron.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
e_nuron.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
e_nuron.o: c:\mingw\include\string.h c:\mingw\include\strings.h
e_nuron.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
e_nuron.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
e_nuron.o: c:\mingw\include\wchar.h
e_nuron.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
e_nuron.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h e_nuron.c
e_nuron.o: e_nuron_err.c e_nuron_err.h
e_padlock.o: ../include/openssl/aes.h ../include/openssl/asn1.h
e_padlock.o: ../include/openssl/bio.h ../include/openssl/buffer.h
e_padlock.o: ../include/openssl/crypto.h ../include/openssl/dso.h
e_padlock.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
e_padlock.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
e_padlock.o: ../include/openssl/engine.h ../include/openssl/err.h
e_padlock.o: ../include/openssl/evp.h ../include/openssl/lhash.h
e_padlock.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
e_padlock.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
e_padlock.o: ../include/openssl/ossl_typ.h ../include/openssl/pkcs7.h
e_padlock.o: ../include/openssl/rand.h ../include/openssl/safestack.h
e_padlock.o: ../include/openssl/sha.h ../include/openssl/stack.h
e_padlock.o: ../include/openssl/symhacks.h ../include/openssl/x509.h
e_padlock.o: ../include/openssl/x509_vfy.h c:\mingw\include\_mingw.h
e_padlock.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
e_padlock.o: c:\mingw\include\errno.h c:\mingw\include\malloc.h
e_padlock.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
e_padlock.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
e_padlock.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
e_padlock.o: c:\mingw\include\string.h c:\mingw\include\strings.h
e_padlock.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
e_padlock.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
e_padlock.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
e_padlock.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
e_padlock.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
e_padlock.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
e_padlock.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
e_padlock.o: c:\mingw\include\winreg.h c:\mingw\include\winsvc.h
e_padlock.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
e_padlock.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
e_padlock.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h e_padlock.c
e_sureware.o: ../include/openssl/asn1.h ../include/openssl/bio.h
e_sureware.o: ../include/openssl/bn.h ../include/openssl/buffer.h
e_sureware.o: ../include/openssl/crypto.h ../include/openssl/dh.h
e_sureware.o: ../include/openssl/dsa.h ../include/openssl/dso.h
e_sureware.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
e_sureware.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
e_sureware.o: ../include/openssl/engine.h ../include/openssl/err.h
e_sureware.o: ../include/openssl/evp.h ../include/openssl/lhash.h
e_sureware.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
e_sureware.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
e_sureware.o: ../include/openssl/ossl_typ.h ../include/openssl/pem.h
e_sureware.o: ../include/openssl/pem2.h ../include/openssl/pkcs7.h
e_sureware.o: ../include/openssl/rand.h ../include/openssl/rsa.h
e_sureware.o: ../include/openssl/safestack.h ../include/openssl/sha.h
e_sureware.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
e_sureware.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h
e_sureware.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
e_sureware.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
e_sureware.o: c:\mingw\include\limits.h c:\mingw\include\msvcrtver.h
e_sureware.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
e_sureware.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
e_sureware.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
e_sureware.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
e_sureware.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
e_sureware.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
e_sureware.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
e_sureware.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
e_sureware.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
e_sureware.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
e_sureware.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
e_sureware.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
e_sureware.o: c:\mingw\include\winver.h
e_sureware.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
e_sureware.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h e_sureware.c
e_sureware.o: e_sureware_err.c e_sureware_err.h vendor_defns/sureware.h
e_ubsec.o: ../include/openssl/asn1.h ../include/openssl/bio.h
e_ubsec.o: ../include/openssl/bn.h ../include/openssl/buffer.h
e_ubsec.o: ../include/openssl/crypto.h ../include/openssl/dh.h
e_ubsec.o: ../include/openssl/dsa.h ../include/openssl/dso.h
e_ubsec.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
e_ubsec.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
e_ubsec.o: ../include/openssl/engine.h ../include/openssl/err.h
e_ubsec.o: ../include/openssl/evp.h ../include/openssl/lhash.h
e_ubsec.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
e_ubsec.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
e_ubsec.o: ../include/openssl/ossl_typ.h ../include/openssl/pkcs7.h
e_ubsec.o: ../include/openssl/rsa.h ../include/openssl/safestack.h
e_ubsec.o: ../include/openssl/sha.h ../include/openssl/stack.h
e_ubsec.o: ../include/openssl/symhacks.h ../include/openssl/x509.h
e_ubsec.o: ../include/openssl/x509_vfy.h c:\mingw\include\_mingw.h
e_ubsec.o: c:\mingw\include\errno.h c:\mingw\include\limits.h
e_ubsec.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
e_ubsec.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
e_ubsec.o: c:\mingw\include\string.h c:\mingw\include\strings.h
e_ubsec.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
e_ubsec.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
e_ubsec.o: c:\mingw\include\wchar.h
e_ubsec.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
e_ubsec.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h e_ubsec.c
e_ubsec.o: e_ubsec_err.c e_ubsec_err.h vendor_defns/hw_ubsec.h
