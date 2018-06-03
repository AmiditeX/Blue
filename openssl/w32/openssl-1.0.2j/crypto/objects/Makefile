#
# OpenSSL/crypto/objects/Makefile
#

DIR=	objects
TOP=	../..
CC=	cc
INCLUDES= -I.. -I$(TOP) -I../../include
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r
PERL=		perl

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile README
TEST=
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC=	o_names.c obj_dat.c obj_lib.c obj_err.c obj_xref.c
LIBOBJ= o_names.o obj_dat.o obj_lib.o obj_err.o obj_xref.o

SRC= $(LIBSRC)

EXHEADER= objects.h obj_mac.h
HEADER=	$(EXHEADER) obj_dat.h obj_xref.h

ALL=    $(GENERAL) $(SRC) $(HEADER)

top:
	(cd ../..; $(MAKE) DIRS=crypto SDIRS=$(DIR) sub_all)

all:	obj_dat.h obj_xref.h lib

lib:	$(LIBOBJ)
	$(AR) $(LIB) $(LIBOBJ)
	$(RANLIB) $(LIB) || echo Never mind.
	@touch lib

obj_dat.h: obj_dat.pl obj_mac.h
	$(PERL) obj_dat.pl obj_mac.h obj_dat.h

# objects.pl both reads and writes obj_mac.num
obj_mac.h: objects.pl objects.txt obj_mac.num
	$(PERL) objects.pl objects.txt obj_mac.num obj_mac.h
	@sleep 1; touch obj_mac.h; sleep 1

obj_xref.h: objxref.pl obj_xref.txt obj_mac.num
	$(PERL) objxref.pl obj_mac.num obj_xref.txt > obj_xref.h
	@sleep 1; touch obj_xref.h; sleep 1

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

update: obj_dat.h obj_mac.h obj_xref.h depend

depend:
	@[ -n "$(MAKEDEPEND)" ] # should be set by upper Makefile...
	$(MAKEDEPEND) -- $(CFLAG) $(INCLUDES) $(DEPFLAG) -- $(PROGS) $(LIBSRC)

dclean:
	$(PERL) -pe 'if (/^# DO NOT DELETE THIS LINE/) {print; exit(0);}' $(MAKEFILE) >Makefile.new
	mv -f Makefile.new $(MAKEFILE)

clean:
	rm -f *.o *.obj lib tags core .pure .nfs* *.old *.bak fluff

# DO NOT DELETE THIS LINE -- make depend depends on it.

o_names.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
o_names.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
o_names.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
o_names.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
o_names.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
o_names.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
o_names.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
o_names.o: c:\mingw\include\_mingw.h c:\mingw\include\errno.h
o_names.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
o_names.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
o_names.o: c:\mingw\include\string.h c:\mingw\include\strings.h
o_names.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
o_names.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
o_names.o: c:\mingw\include\wchar.h
o_names.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
o_names.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h o_names.c
obj_dat.o: ../../e_os.h ../../include/openssl/asn1.h
obj_dat.o: ../../include/openssl/bio.h ../../include/openssl/bn.h
obj_dat.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
obj_dat.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
obj_dat.o: ../../include/openssl/lhash.h ../../include/openssl/obj_mac.h
obj_dat.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
obj_dat.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
obj_dat.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
obj_dat.o: ../../include/openssl/symhacks.h ../../ms/applink.c
obj_dat.o: ../../ms/uplink.h ../cryptlib.h c:\mingw\include\_mingw.h
obj_dat.o: c:\mingw\include\basetsd.h c:\mingw\include\ctype.h
obj_dat.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
obj_dat.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
obj_dat.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
obj_dat.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
obj_dat.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
obj_dat.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
obj_dat.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
obj_dat.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
obj_dat.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
obj_dat.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
obj_dat.o: c:\mingw\include\wctype.h c:\mingw\include\winbase.h
obj_dat.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
obj_dat.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
obj_dat.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
obj_dat.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
obj_dat.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
obj_dat.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
obj_dat.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
obj_dat.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
obj_dat.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h obj_dat.c obj_dat.h
obj_err.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
obj_err.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
obj_err.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
obj_err.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
obj_err.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
obj_err.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
obj_err.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
obj_err.o: c:\mingw\include\_mingw.h c:\mingw\include\errno.h
obj_err.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
obj_err.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
obj_err.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
obj_err.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
obj_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
obj_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h obj_err.c
obj_lib.o: ../../e_os.h ../../include/openssl/asn1.h
obj_lib.o: ../../include/openssl/bio.h ../../include/openssl/buffer.h
obj_lib.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
obj_lib.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
obj_lib.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
obj_lib.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
obj_lib.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
obj_lib.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
obj_lib.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h
obj_lib.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
obj_lib.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
obj_lib.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
obj_lib.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
obj_lib.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
obj_lib.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
obj_lib.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
obj_lib.o: c:\mingw\include\string.h c:\mingw\include\strings.h
obj_lib.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
obj_lib.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
obj_lib.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
obj_lib.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
obj_lib.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
obj_lib.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
obj_lib.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
obj_lib.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
obj_lib.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
obj_lib.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
obj_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
obj_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h obj_lib.c
obj_xref.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
obj_xref.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
obj_xref.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
obj_xref.o: ../../include/openssl/opensslconf.h
obj_xref.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
obj_xref.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
obj_xref.o: ../../include/openssl/symhacks.h c:\mingw\include\_mingw.h
obj_xref.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
obj_xref.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
obj_xref.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
obj_xref.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
obj_xref.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
obj_xref.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h obj_xref.c
obj_xref.o: obj_xref.h
