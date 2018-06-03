#
# test/Makefile
#

DIR=		test
TOP=		..
CC=		cc
INCLUDES=	-I$(TOP) -I../include $(KRB5_INCLUDES)
CFLAG=		-g
MAKEDEPEND=	$(TOP)/util/domd $(TOP) -MD $(MAKEDEPPROG)
PERL=		perl
# KRB5 stuff
KRB5_INCLUDES=
LIBKRB5=
TEST=		igetest.c

PEX_LIBS=
EX_LIBS= #-lnsl -lsocket

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile maketests.com \
	tests.com testenc.com tx509.com trsa.com tcrl.com tsid.com treq.com \
	tpkcs7.com tpkcs7d.com tverify.com testgen.com testss.com testssl.com \
	testca.com VMSca-response.1 VMSca-response.2

DLIBCRYPTO= ../libcrypto.a
DLIBSSL= ../libssl.a
LIBCRYPTO= -L.. -lcrypto
LIBSSL= -L.. -lssl

BNTEST=		bntest
ECTEST=		ectest
ECDSATEST=	ecdsatest
ECDHTEST=	ecdhtest
EXPTEST=	exptest
IDEATEST=	ideatest
SHATEST=	shatest
SHA1TEST=	sha1test
SHA256TEST=	sha256t
SHA512TEST=	sha512t
MDC2TEST=	mdc2test
RMDTEST=	rmdtest
MD2TEST=	md2test
MD4TEST=	md4test
MD5TEST=	md5test
HMACTEST=	hmactest
WPTEST=		wp_test
RC2TEST=	rc2test
RC4TEST=	rc4test
RC5TEST=	rc5test
BFTEST=		bftest
CASTTEST=	casttest
DESTEST=	destest
RANDTEST=	randtest
DHTEST=		dhtest
DSATEST=	dsatest
METHTEST=	methtest
SSLTEST=	ssltest
RSATEST=	rsa_test
ENGINETEST=	enginetest
EVPTEST=	evp_test
EVPEXTRATEST=evp_extra_test
IGETEST=	igetest
JPAKETEST=	jpaketest
SRPTEST=	srptest
V3NAMETEST=	v3nametest
ASN1TEST=	asn1test
HEARTBEATTEST=  heartbeat_test
CONSTTIMETEST=  constant_time_test
VERIFYEXTRATEST=	verify_extra_test
CLIENTHELLOTEST=	clienthellotest
BADDTLSTEST=	bad_dtls_test
SSLV2CONFTEST = 	sslv2conftest
DTLSTEST =	dtlstest

TESTS=		alltests

EXE=	$(BNTEST)$(EXE_EXT) $(ECTEST)$(EXE_EXT)  $(ECDSATEST)$(EXE_EXT) $(ECDHTEST)$(EXE_EXT) $(IDEATEST)$(EXE_EXT) \
	$(MD2TEST)$(EXE_EXT)  $(MD4TEST)$(EXE_EXT) $(MD5TEST)$(EXE_EXT) $(HMACTEST)$(EXE_EXT) $(WPTEST)$(EXE_EXT) \
	$(RC2TEST)$(EXE_EXT) $(RC4TEST)$(EXE_EXT) $(RC5TEST)$(EXE_EXT) \
	$(DESTEST)$(EXE_EXT) $(SHATEST)$(EXE_EXT) $(SHA1TEST)$(EXE_EXT) $(SHA256TEST)$(EXE_EXT) $(SHA512TEST)$(EXE_EXT) \
	$(MDC2TEST)$(EXE_EXT) $(RMDTEST)$(EXE_EXT) \
	$(RANDTEST)$(EXE_EXT) $(DHTEST)$(EXE_EXT) $(ENGINETEST)$(EXE_EXT) \
	$(BFTEST)$(EXE_EXT) $(CASTTEST)$(EXE_EXT) $(SSLTEST)$(EXE_EXT) $(EXPTEST)$(EXE_EXT) $(DSATEST)$(EXE_EXT) $(RSATEST)$(EXE_EXT) \
	$(EVPTEST)$(EXE_EXT) $(EVPEXTRATEST)$(EXE_EXT) $(IGETEST)$(EXE_EXT) $(JPAKETEST)$(EXE_EXT) $(SRPTEST)$(EXE_EXT) \
	$(ASN1TEST)$(EXE_EXT) $(V3NAMETEST)$(EXE_EXT) $(HEARTBEATTEST)$(EXE_EXT) \
	$(CONSTTIMETEST)$(EXE_EXT) $(VERIFYEXTRATEST)$(EXE_EXT) \
	$(CLIENTHELLOTEST)$(EXE_EXT) $(SSLV2CONFTEST)$(EXE_EXT) $(DTLSTEST)$(EXE_EXT) \
	$(BADDTLSTEST)$(EXE_EXT)

# $(METHTEST)$(EXE_EXT)

OBJ=	$(BNTEST).o $(ECTEST).o  $(ECDSATEST).o $(ECDHTEST).o $(IDEATEST).o \
	$(MD2TEST).o $(MD4TEST).o $(MD5TEST).o \
	$(HMACTEST).o $(WPTEST).o \
	$(RC2TEST).o $(RC4TEST).o $(RC5TEST).o \
	$(DESTEST).o $(SHATEST).o $(SHA1TEST).o $(SHA256TEST).o $(SHA512TEST).o \
	$(MDC2TEST).o $(RMDTEST).o \
	$(RANDTEST).o $(DHTEST).o $(ENGINETEST).o $(CASTTEST).o \
	$(BFTEST).o  $(SSLTEST).o  $(DSATEST).o  $(EXPTEST).o $(RSATEST).o \
	$(EVPTEST).o $(EVPEXTRATEST).o $(IGETEST).o $(JPAKETEST).o $(ASN1TEST).o $(V3NAMETEST).o \
	$(HEARTBEATTEST).o $(CONSTTIMETEST).o $(VERIFYEXTRATEST).o \
	$(CLIENTHELLOTEST).o  $(SSLV2CONFTEST).o $(DTLSTEST).o ssltestlib.o \
	$(BADDTLSTEST).o

SRC=	$(BNTEST).c $(ECTEST).c  $(ECDSATEST).c $(ECDHTEST).c $(IDEATEST).c \
	$(MD2TEST).c  $(MD4TEST).c $(MD5TEST).c \
	$(HMACTEST).c $(WPTEST).c \
	$(RC2TEST).c $(RC4TEST).c $(RC5TEST).c \
	$(DESTEST).c $(SHATEST).c $(SHA1TEST).c $(MDC2TEST).c $(RMDTEST).c \
	$(RANDTEST).c $(DHTEST).c $(ENGINETEST).c $(CASTTEST).c \
	$(BFTEST).c  $(SSLTEST).c $(DSATEST).c   $(EXPTEST).c $(RSATEST).c \
	$(EVPTEST).c $(EVPEXTRATEST).c $(IGETEST).c $(JPAKETEST).c $(SRPTEST).c $(ASN1TEST).c \
	$(V3NAMETEST).c $(HEARTBEATTEST).c $(CONSTTIMETEST).c $(VERIFYEXTRATEST).c \
	$(CLIENTHELLOTEST).c  $(SSLV2CONFTEST).c $(DTLSTEST).c ssltestlib.c \
	$(BADDTLSTEST).c

EXHEADER= 
HEADER=	testutil.h ssltestlib.h $(EXHEADER)

ALL=    $(GENERAL) $(SRC) $(HEADER)

top:
	(cd ..; $(MAKE) DIRS=$(DIR) TESTS=$(TESTS) all)

all:	exe

exe:	$(EXE) dummytest$(EXE_EXT)

files:
	$(PERL) $(TOP)/util/files.pl Makefile >> $(TOP)/MINFO

links:

generate: $(SRC)
$(SRC):
	@sh $(TOP)/util/point.sh dummytest.c $@

errors:

install:

tags:
	ctags $(SRC)

tests:	exe apps $(TESTS)

apps:
	@(cd ..; $(MAKE) DIRS=apps all)

alltests: \
	test_des test_idea test_sha test_md4 test_md5 test_hmac \
	test_md2 test_mdc2 test_wp \
	test_rmd test_rc2 test_rc4 test_rc5 test_bf test_cast test_aes \
	test_rand test_bn test_ec test_ecdsa test_ecdh \
	test_enc test_x509 test_rsa test_crl test_sid \
	test_gen test_req test_pkcs7 test_verify test_dh test_dsa \
	test_ss test_ca test_engine test_evp test_evp_extra test_ssl test_tsa test_ige \
	test_jpake test_srp test_cms test_ocsp test_v3name test_heartbeat \
	test_constant_time test_verify_extra test_clienthello test_sslv2conftest \
	test_dtls test_bad_dtls

test_evp: $(EVPTEST)$(EXE_EXT) evptests.txt
	../util/shlib_wrap.sh ./$(EVPTEST) evptests.txt

test_evp_extra: $(EVPEXTRATEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(EVPEXTRATEST)

test_des: $(DESTEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(DESTEST)

test_idea: $(IDEATEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(IDEATEST)

test_sha: $(SHATEST)$(EXE_EXT) $(SHA1TEST)$(EXE_EXT) $(SHA256TEST)$(EXE_EXT) $(SHA512TEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(SHATEST)
	../util/shlib_wrap.sh ./$(SHA1TEST)
	../util/shlib_wrap.sh ./$(SHA256TEST)
	../util/shlib_wrap.sh ./$(SHA512TEST)

test_mdc2: $(MDC2TEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(MDC2TEST)

test_md5: $(MD5TEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(MD5TEST)

test_md4: $(MD4TEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(MD4TEST)

test_hmac: $(HMACTEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(HMACTEST)

test_wp: $(WPTEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(WPTEST)

test_md2: $(MD2TEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(MD2TEST)

test_rmd: $(RMDTEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(RMDTEST)

test_bf: $(BFTEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(BFTEST)

test_cast: $(CASTTEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(CASTTEST)

test_rc2: $(RC2TEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(RC2TEST)

test_rc4: $(RC4TEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(RC4TEST)

test_rc5: $(RC5TEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(RC5TEST)

test_rand: $(RANDTEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(RANDTEST)

test_enc: ../apps/openssl$(EXE_EXT) testenc
	@sh ./testenc

test_x509: ../apps/openssl$(EXE_EXT) tx509 testx509.pem v3-cert1.pem v3-cert2.pem
	echo test normal x509v1 certificate
	sh ./tx509 2>/dev/null
	echo test first x509v3 certificate
	sh ./tx509 v3-cert1.pem 2>/dev/null
	echo test second x509v3 certificate
	sh ./tx509 v3-cert2.pem 2>/dev/null

test_rsa: $(RSATEST)$(EXE_EXT) ../apps/openssl$(EXE_EXT) trsa testrsa.pem
	@sh ./trsa 2>/dev/null
	../util/shlib_wrap.sh ./$(RSATEST)

test_crl: ../apps/openssl$(EXE_EXT) tcrl testcrl.pem
	@sh ./tcrl 2>/dev/null

test_sid: ../apps/openssl$(EXE_EXT) tsid testsid.pem
	@sh ./tsid 2>/dev/null

test_req: ../apps/openssl$(EXE_EXT) treq testreq.pem testreq2.pem
	@sh ./treq 2>/dev/null
	@sh ./treq testreq2.pem 2>/dev/null

test_pkcs7: ../apps/openssl$(EXE_EXT) tpkcs7 tpkcs7d testp7.pem pkcs7-1.pem
	@sh ./tpkcs7 2>/dev/null
	@sh ./tpkcs7d 2>/dev/null

test_bn: $(BNTEST)$(EXE_EXT) $(EXPTEST)$(EXE_EXT) bctest
	@echo starting big number library test, could take a while...
	@../util/shlib_wrap.sh ./$(BNTEST) >tmp.bntest
	@echo quit >>tmp.bntest
	@echo "running bc"
	@<tmp.bntest sh -c "`sh ./bctest ignore`" | $(PERL) -e '$$i=0; while (<STDIN>) {if (/^test (.*)/) {print STDERR "\nverify $$1";} elsif (!/^0\r?$$/) {die "\nFailed! bc: $$_";} else {print STDERR "."; $$i++;}} print STDERR "\n$$i tests passed\n"'
	@echo 'test a^b%c implementations'
	../util/shlib_wrap.sh ./$(EXPTEST)

test_ec: $(ECTEST)$(EXE_EXT)
	@echo 'test elliptic curves'
	../util/shlib_wrap.sh ./$(ECTEST)

test_ecdsa: $(ECDSATEST)$(EXE_EXT)
	@echo 'test ecdsa'
	../util/shlib_wrap.sh ./$(ECDSATEST)

test_ecdh: $(ECDHTEST)$(EXE_EXT)
	@echo 'test ecdh'
	../util/shlib_wrap.sh ./$(ECDHTEST)

test_verify: ../apps/openssl$(EXE_EXT)
	@echo "The following command should have some OK's and some failures"
	@echo "There are definitly a few expired certificates"
	../util/shlib_wrap.sh ../apps/openssl verify -CApath ../certs/demo ../certs/demo/*.pem

test_dh: $(DHTEST)$(EXE_EXT)
	@echo "Generate a set of DH parameters"
	../util/shlib_wrap.sh ./$(DHTEST)

test_dsa: $(DSATEST)$(EXE_EXT)
	@echo "Generate a set of DSA parameters"
	../util/shlib_wrap.sh ./$(DSATEST)
	../util/shlib_wrap.sh ./$(DSATEST) -app2_1

test_gen testreq.pem: ../apps/openssl$(EXE_EXT) testgen test.cnf
	@echo "Generate and verify a certificate request"
	@sh ./testgen

test_ss keyU.ss certU.ss certCA.ss certP1.ss keyP1.ss certP2.ss keyP2.ss \
		intP1.ss intP2.ss: testss CAss.cnf Uss.cnf P1ss.cnf P2ss.cnf \
                                   ../apps/openssl$(EXE_EXT)
	@echo "Generate and certify a test certificate"
	@sh ./testss
	@cat certCA.ss certU.ss > intP1.ss
	@cat certCA.ss certU.ss certP1.ss > intP2.ss

test_engine:  $(ENGINETEST)$(EXE_EXT)
	@echo "Manipulate the ENGINE structures"
	../util/shlib_wrap.sh ./$(ENGINETEST)

test_ssl: keyU.ss certU.ss certCA.ss certP1.ss keyP1.ss certP2.ss keyP2.ss \
		intP1.ss intP2.ss $(SSLTEST)$(EXE_EXT) testssl testsslproxy \
		../apps/server2.pem serverinfo.pem
	@echo "test SSL protocol"
	@if [ -n "$(FIPSCANLIB)" ]; then \
	  sh ./testfipsssl keyU.ss certU.ss certCA.ss; \
	fi
	../util/shlib_wrap.sh ./$(SSLTEST) -test_cipherlist
	@sh ./testssl keyU.ss certU.ss certCA.ss
	@sh ./testsslproxy keyP1.ss certP1.ss intP1.ss
	@sh ./testsslproxy keyP2.ss certP2.ss intP2.ss

test_ca: ../apps/openssl$(EXE_EXT) testca CAss.cnf Uss.cnf
	@if ../util/shlib_wrap.sh ../apps/openssl no-rsa; then \
	  echo "skipping CA.sh test -- requires RSA"; \
	else \
	  echo "Generate and certify a test certificate via the 'ca' program"; \
	  sh ./testca; \
	fi

test_aes: #$(AESTEST)
#	@echo "test Rijndael"
#	../util/shlib_wrap.sh ./$(AESTEST)

test_tsa: ../apps/openssl$(EXE_EXT) testtsa CAtsa.cnf ../util/shlib_wrap.sh
	@if ../util/shlib_wrap.sh ../apps/openssl no-rsa; then \
	  echo "skipping testtsa test -- requires RSA"; \
	else \
	  sh ./testtsa; \
	fi

test_ige: $(IGETEST)$(EXE_EXT)
	@echo "Test IGE mode"
	../util/shlib_wrap.sh ./$(IGETEST)

test_jpake: $(JPAKETEST)$(EXE_EXT)
	@echo "Test JPAKE"
	../util/shlib_wrap.sh ./$(JPAKETEST)

test_cms: ../apps/openssl$(EXE_EXT) cms-test.pl smcont.txt
	@echo "CMS consistency test"
	$(PERL) cms-test.pl

test_srp: $(SRPTEST)$(EXE_EXT)
	@echo "Test SRP"
	../util/shlib_wrap.sh ./srptest

test_ocsp: ../apps/openssl$(EXE_EXT) tocsp
	@echo "Test OCSP"
	@sh ./tocsp

test_v3name: $(V3NAMETEST)$(EXE_EXT)
	@echo "Test X509v3_check_*"
	../util/shlib_wrap.sh ./$(V3NAMETEST)

test_heartbeat: $(HEARTBEATTEST)$(EXE_EXT)
	../util/shlib_wrap.sh ./$(HEARTBEATTEST)

test_constant_time: $(CONSTTIMETEST)$(EXE_EXT)
	@echo "Test constant time utilites"
	../util/shlib_wrap.sh ./$(CONSTTIMETEST)

test_verify_extra: $(VERIFYEXTRATEST)$(EXE_EXT)
	@echo $(START) $@
	../util/shlib_wrap.sh ./$(VERIFYEXTRATEST)

test_clienthello: $(CLIENTHELLOTEST)$(EXE_EXT)
	@echo $(START) $@
	../util/shlib_wrap.sh ./$(CLIENTHELLOTEST)

test_bad_dtls: $(BADDTLSTEST)$(EXE_EXT)
	@echo $(START) $@
	../util/shlib_wrap.sh ./$(BADDTLSTEST)

test_sslv2conftest: $(SSLV2CONFTEST)$(EXE_EXT)
	@echo $(START) $@
	../util/shlib_wrap.sh ./$(SSLV2CONFTEST)

test_dtls: $(DTLSTEST)$(EXE_EXT)
	@echo $(START) $@
	../util/shlib_wrap.sh ./$(DTLSTEST) ../apps/server.pem ../apps/server.pem

lint:
	lint -DLINT $(INCLUDES) $(SRC)>fluff

update: local_depend
	@if [ -z "$(THIS)" ]; then $(MAKE) -f $(TOP)/Makefile reflect THIS=$@; fi

depend: local_depend
	@if [ -z "$(THIS)" ]; then $(MAKE) -f $(TOP)/Makefile reflect THIS=$@; fi
local_depend:
	@[ -z "$(THIS)" ] || $(MAKEDEPEND) -- $(CFLAG) $(INCLUDES) $(DEPFLAG) -- $(PROGS) $(SRC)

dclean:
	$(PERL) -pe 'if (/^# DO NOT DELETE THIS LINE/) {print; exit(0);}' $(MAKEFILE) >Makefile.new
	mv -f Makefile.new $(MAKEFILE)
	rm -f $(SRC) $(SHA256TEST).c $(SHA512TEST).c evptests.txt newkey.pem testkey.pem \
			testreq.pem

clean:
	rm -f .rnd tmp.bntest tmp.bctest *.o *.obj *.dll lib tags core .pure .nfs* *.old *.bak fluff $(EXE) *.ss *.srl log dummytest

$(DLIBSSL):
	(cd ..; $(MAKE) build_libssl)

$(DLIBCRYPTO):
	(cd ..; $(MAKE) build_libcrypto)

BUILD_CMD=shlib_target=; if [ -n "$(SHARED_LIBS)" ]; then \
		shlib_target="$(SHLIB_TARGET)"; \
	fi; \
	LIBRARIES="$(LIBSSL) $(LIBCRYPTO) $(LIBKRB5)"; \
	$(MAKE) -f $(TOP)/Makefile.shared -e \
		CC="$${CC}" APPNAME=$$target$(EXE_EXT) OBJECTS="$$target.o $$exobj" \
		LIBDEPS="$(PEX_LIBS) $$LIBRARIES $(EX_LIBS)" \
		link_app.$${shlib_target}

FIPS_BUILD_CMD=shlib_target=; if [ -n "$(SHARED_LIBS)" ]; then \
		shlib_target="$(SHLIB_TARGET)"; \
	fi; \
	LIBRARIES="$(LIBSSL) $(LIBCRYPTO) $(LIBKRB5)"; \
	if [ -z "$(SHARED_LIBS)" -a -n "$(FIPSCANLIB)" ] ; then \
		FIPSLD_CC="$(CC)"; CC=$(FIPSDIR)/bin/fipsld; export CC FIPSLD_CC; \
	fi; \
	$(MAKE) -f $(TOP)/Makefile.shared -e \
		CC="$${CC}" APPNAME=$$target$(EXE_EXT) OBJECTS="$$target.o" \
		LIBDEPS="$(PEX_LIBS) $$LIBRARIES $(EX_LIBS)" \
		link_app.$${shlib_target}

BUILD_CMD_STATIC=shlib_target=; \
	LIBRARIES="$(DLIBSSL) $(DLIBCRYPTO) $(LIBKRB5)"; \
	$(MAKE) -f $(TOP)/Makefile.shared -e \
		APPNAME=$$target$(EXE_EXT) OBJECTS="$$target.o" \
		LIBDEPS="$(PEX_LIBS) $$LIBRARIES $(EX_LIBS)" \
		link_app.$${shlib_target}

$(RSATEST)$(EXE_EXT): $(RSATEST).o $(DLIBCRYPTO)
	@target=$(RSATEST); $(BUILD_CMD)

$(BNTEST)$(EXE_EXT): $(BNTEST).o $(DLIBCRYPTO)
	@target=$(BNTEST); $(BUILD_CMD)

$(ECTEST)$(EXE_EXT): $(ECTEST).o $(DLIBCRYPTO)
	@target=$(ECTEST); $(BUILD_CMD)

$(EXPTEST)$(EXE_EXT): $(EXPTEST).o $(DLIBCRYPTO)
	@target=$(EXPTEST); $(BUILD_CMD)

$(IDEATEST)$(EXE_EXT): $(IDEATEST).o $(DLIBCRYPTO)
	@target=$(IDEATEST); $(BUILD_CMD)

$(MD2TEST)$(EXE_EXT): $(MD2TEST).o $(DLIBCRYPTO)
	@target=$(MD2TEST); $(BUILD_CMD)

$(SHATEST)$(EXE_EXT): $(SHATEST).o $(DLIBCRYPTO)
	@target=$(SHATEST); $(BUILD_CMD)

$(SHA1TEST)$(EXE_EXT): $(SHA1TEST).o $(DLIBCRYPTO)
	@target=$(SHA1TEST); $(BUILD_CMD)

$(SHA256TEST)$(EXE_EXT): $(SHA256TEST).o $(DLIBCRYPTO)
	@target=$(SHA256TEST); $(BUILD_CMD)

$(SHA512TEST)$(EXE_EXT): $(SHA512TEST).o $(DLIBCRYPTO)
	@target=$(SHA512TEST); $(BUILD_CMD)

$(RMDTEST)$(EXE_EXT): $(RMDTEST).o $(DLIBCRYPTO)
	@target=$(RMDTEST); $(BUILD_CMD)

$(MDC2TEST)$(EXE_EXT): $(MDC2TEST).o $(DLIBCRYPTO)
	@target=$(MDC2TEST); $(BUILD_CMD)

$(MD4TEST)$(EXE_EXT): $(MD4TEST).o $(DLIBCRYPTO)
	@target=$(MD4TEST); $(BUILD_CMD)

$(MD5TEST)$(EXE_EXT): $(MD5TEST).o $(DLIBCRYPTO)
	@target=$(MD5TEST); $(BUILD_CMD)

$(HMACTEST)$(EXE_EXT): $(HMACTEST).o $(DLIBCRYPTO)
	@target=$(HMACTEST); $(BUILD_CMD)

$(WPTEST)$(EXE_EXT): $(WPTEST).o $(DLIBCRYPTO)
	@target=$(WPTEST); $(BUILD_CMD)

$(RC2TEST)$(EXE_EXT): $(RC2TEST).o $(DLIBCRYPTO)
	@target=$(RC2TEST); $(BUILD_CMD)

$(BFTEST)$(EXE_EXT): $(BFTEST).o $(DLIBCRYPTO)
	@target=$(BFTEST); $(BUILD_CMD)

$(CASTTEST)$(EXE_EXT): $(CASTTEST).o $(DLIBCRYPTO)
	@target=$(CASTTEST); $(BUILD_CMD)

$(RC4TEST)$(EXE_EXT): $(RC4TEST).o $(DLIBCRYPTO)
	@target=$(RC4TEST); $(BUILD_CMD)

$(RC5TEST)$(EXE_EXT): $(RC5TEST).o $(DLIBCRYPTO)
	@target=$(RC5TEST); $(BUILD_CMD)

$(DESTEST)$(EXE_EXT): $(DESTEST).o $(DLIBCRYPTO)
	@target=$(DESTEST); $(BUILD_CMD)

$(RANDTEST)$(EXE_EXT): $(RANDTEST).o $(DLIBCRYPTO)
	@target=$(RANDTEST); $(BUILD_CMD)

$(DHTEST)$(EXE_EXT): $(DHTEST).o $(DLIBCRYPTO)
	@target=$(DHTEST); $(BUILD_CMD)

$(DSATEST)$(EXE_EXT): $(DSATEST).o $(DLIBCRYPTO)
	@target=$(DSATEST); $(BUILD_CMD)

$(METHTEST)$(EXE_EXT): $(METHTEST).o $(DLIBCRYPTO)
	@target=$(METHTEST); $(BUILD_CMD)

$(SSLTEST)$(EXE_EXT): $(SSLTEST).o $(DLIBSSL) $(DLIBCRYPTO)
	@target=$(SSLTEST); $(FIPS_BUILD_CMD)

$(ENGINETEST)$(EXE_EXT): $(ENGINETEST).o $(DLIBCRYPTO)
	@target=$(ENGINETEST); $(BUILD_CMD)

$(EVPTEST)$(EXE_EXT): $(EVPTEST).o $(DLIBCRYPTO)
	@target=$(EVPTEST); $(BUILD_CMD)

$(EVPEXTRATEST)$(EXE_EXT): $(EVPEXTRATEST).o $(DLIBCRYPTO)
	@target=$(EVPEXTRATEST); $(BUILD_CMD)

$(ECDSATEST)$(EXE_EXT): $(ECDSATEST).o $(DLIBCRYPTO)
	@target=$(ECDSATEST); $(BUILD_CMD)

$(ECDHTEST)$(EXE_EXT): $(ECDHTEST).o $(DLIBCRYPTO)
	@target=$(ECDHTEST); $(BUILD_CMD)

$(IGETEST)$(EXE_EXT): $(IGETEST).o $(DLIBCRYPTO)
	@target=$(IGETEST); $(BUILD_CMD)

$(JPAKETEST)$(EXE_EXT): $(JPAKETEST).o $(DLIBCRYPTO)
	@target=$(JPAKETEST); $(BUILD_CMD)

$(ASN1TEST)$(EXE_EXT): $(ASN1TEST).o $(DLIBCRYPTO)
	@target=$(ASN1TEST); $(BUILD_CMD)

$(SRPTEST)$(EXE_EXT): $(SRPTEST).o $(DLIBCRYPTO)
	@target=$(SRPTEST); $(BUILD_CMD)

$(V3NAMETEST)$(EXE_EXT): $(V3NAMETEST).o $(DLIBCRYPTO)
	@target=$(V3NAMETEST); $(BUILD_CMD)

$(HEARTBEATTEST)$(EXE_EXT): $(HEARTBEATTEST).o $(DLIBCRYPTO)
	@target=$(HEARTBEATTEST); $(BUILD_CMD_STATIC)

$(CONSTTIMETEST)$(EXE_EXT): $(CONSTTIMETEST).o
	@target=$(CONSTTIMETEST) $(BUILD_CMD)

$(VERIFYEXTRATEST)$(EXE_EXT): $(VERIFYEXTRATEST).o
	@target=$(VERIFYEXTRATEST) $(BUILD_CMD)

$(CLIENTHELLOTEST)$(EXE_EXT): $(CLIENTHELLOTEST).o
	@target=$(CLIENTHELLOTEST) $(BUILD_CMD)

$(BADDTLSTEST)$(EXE_EXT): $(BADDTLSTEST).o
	@target=$(BADDTLSTEST) $(BUILD_CMD)

$(SSLV2CONFTEST)$(EXE_EXT): $(SSLV2CONFTEST).o
	@target=$(SSLV2CONFTEST) $(BUILD_CMD)

$(DTLSTEST)$(EXE_EXT): $(DTLSTEST).o ssltestlib.o $(DLIBSSL) $(DLIBCRYPTO)
	@target=$(DTLSTEST); exobj=ssltestlib.o; $(BUILD_CMD)

#$(AESTEST).o: $(AESTEST).c
#	$(CC) -c $(CFLAGS) -DINTERMEDIATE_VALUE_KAT -DTRACE_KAT_MCT $(AESTEST).c

#$(AESTEST)$(EXE_EXT): $(AESTEST).o $(DLIBCRYPTO)
#	if [ "$(SHLIB_TARGET)" = "hpux-shared" -o "$(SHLIB_TARGET)" = "darwin-shared" ] ; then \
#	  $(CC) -o $(AESTEST)$(EXE_EXT) $(CFLAGS) $(AESTEST).o $(PEX_LIBS) $(DLIBCRYPTO) $(EX_LIBS) ; \
#	else \
#	  $(CC) -o $(AESTEST)$(EXE_EXT) $(CFLAGS) $(AESTEST).o $(PEX_LIBS) $(LIBCRYPTO) $(EX_LIBS) ; \
#	fi

dummytest$(EXE_EXT): dummytest.o $(DLIBCRYPTO)
	@target=dummytest; $(BUILD_CMD)

# DO NOT DELETE THIS LINE -- make depend depends on it.

asn1test.o: ../include/openssl/asn1.h ../include/openssl/asn1_mac.h
asn1test.o: ../include/openssl/bio.h ../include/openssl/buffer.h
asn1test.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
asn1test.o: ../include/openssl/ec.h ../include/openssl/ecdh.h
asn1test.o: ../include/openssl/ecdsa.h ../include/openssl/evp.h
asn1test.o: ../include/openssl/lhash.h ../include/openssl/obj_mac.h
asn1test.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
asn1test.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
asn1test.o: ../include/openssl/pkcs7.h ../include/openssl/safestack.h
asn1test.o: ../include/openssl/sha.h ../include/openssl/stack.h
asn1test.o: ../include/openssl/symhacks.h ../include/openssl/x509.h
asn1test.o: ../include/openssl/x509_vfy.h asn1test.c c:\mingw\include\_mingw.h
asn1test.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
asn1test.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
asn1test.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
asn1test.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
asn1test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
asn1test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bad_dtls_test.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
bad_dtls_test.o: ../include/openssl/buffer.h ../include/openssl/comp.h
bad_dtls_test.o: ../include/openssl/crypto.h ../include/openssl/dtls1.h
bad_dtls_test.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
bad_dtls_test.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
bad_dtls_test.o: ../include/openssl/err.h ../include/openssl/evp.h
bad_dtls_test.o: ../include/openssl/hmac.h ../include/openssl/kssl.h
bad_dtls_test.o: ../include/openssl/lhash.h ../include/openssl/obj_mac.h
bad_dtls_test.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
bad_dtls_test.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
bad_dtls_test.o: ../include/openssl/pem.h ../include/openssl/pem2.h
bad_dtls_test.o: ../include/openssl/pkcs7.h ../include/openssl/pqueue.h
bad_dtls_test.o: ../include/openssl/rand.h ../include/openssl/safestack.h
bad_dtls_test.o: ../include/openssl/sha.h ../include/openssl/srtp.h
bad_dtls_test.o: ../include/openssl/ssl.h ../include/openssl/ssl2.h
bad_dtls_test.o: ../include/openssl/ssl23.h ../include/openssl/ssl3.h
bad_dtls_test.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
bad_dtls_test.o: ../include/openssl/tls1.h ../include/openssl/x509.h
bad_dtls_test.o: ../include/openssl/x509_vfy.h bad_dtls_test.c
bad_dtls_test.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
bad_dtls_test.o: c:\mingw\include\ctype.h c:\mingw\include\dbt.h
bad_dtls_test.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
bad_dtls_test.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
bad_dtls_test.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
bad_dtls_test.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
bad_dtls_test.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
bad_dtls_test.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
bad_dtls_test.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
bad_dtls_test.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
bad_dtls_test.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
bad_dtls_test.o: c:\mingw\include\wctype.h c:\mingw\include\winbase.h
bad_dtls_test.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
bad_dtls_test.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
bad_dtls_test.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
bad_dtls_test.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
bad_dtls_test.o: c:\mingw\include\winreg.h c:\mingw\include\winsock.h
bad_dtls_test.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
bad_dtls_test.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
bad_dtls_test.o: c:\mingw\include\ws2tcpip.h
bad_dtls_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bad_dtls_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bftest.o: ../e_os.h ../include/openssl/blowfish.h ../include/openssl/e_os2.h
bftest.o: ../include/openssl/opensslconf.h bftest.c c:\mingw\include\_mingw.h
bftest.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
bftest.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
bftest.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
bftest.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
bftest.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
bftest.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
bftest.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
bftest.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
bftest.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
bftest.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
bftest.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
bftest.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
bftest.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
bftest.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
bftest.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
bftest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
bftest.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
bftest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bftest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bntest.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
bntest.o: ../include/openssl/bn.h ../include/openssl/buffer.h
bntest.o: ../include/openssl/crypto.h ../include/openssl/dh.h
bntest.o: ../include/openssl/dsa.h ../include/openssl/e_os2.h
bntest.o: ../include/openssl/ec.h ../include/openssl/ecdh.h
bntest.o: ../include/openssl/ecdsa.h ../include/openssl/err.h
bntest.o: ../include/openssl/evp.h ../include/openssl/lhash.h
bntest.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
bntest.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
bntest.o: ../include/openssl/ossl_typ.h ../include/openssl/pkcs7.h
bntest.o: ../include/openssl/rand.h ../include/openssl/rsa.h
bntest.o: ../include/openssl/safestack.h ../include/openssl/sha.h
bntest.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
bntest.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h bntest.c
bntest.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
bntest.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
bntest.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
bntest.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
bntest.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
bntest.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
bntest.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
bntest.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
bntest.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
bntest.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
bntest.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
bntest.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
bntest.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
bntest.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
bntest.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
bntest.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
bntest.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
bntest.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
bntest.o: c:\mingw\include\ws2tcpip.h
bntest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bntest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
casttest.o: ../e_os.h ../include/openssl/cast.h ../include/openssl/e_os2.h
casttest.o: ../include/openssl/opensslconf.h c:\mingw\include\_mingw.h
casttest.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
casttest.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
casttest.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
casttest.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
casttest.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
casttest.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
casttest.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
casttest.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
casttest.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
casttest.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
casttest.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
casttest.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
casttest.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
casttest.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
casttest.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
casttest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
casttest.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
casttest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
casttest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h casttest.c
clienthellotest.o: ../include/openssl/asn1.h ../include/openssl/bio.h
clienthellotest.o: ../include/openssl/buffer.h ../include/openssl/comp.h
clienthellotest.o: ../include/openssl/crypto.h ../include/openssl/dtls1.h
clienthellotest.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
clienthellotest.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
clienthellotest.o: ../include/openssl/err.h ../include/openssl/evp.h
clienthellotest.o: ../include/openssl/hmac.h ../include/openssl/kssl.h
clienthellotest.o: ../include/openssl/lhash.h ../include/openssl/obj_mac.h
clienthellotest.o: ../include/openssl/objects.h
clienthellotest.o: ../include/openssl/opensslconf.h
clienthellotest.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
clienthellotest.o: ../include/openssl/pem.h ../include/openssl/pem2.h
clienthellotest.o: ../include/openssl/pkcs7.h ../include/openssl/pqueue.h
clienthellotest.o: ../include/openssl/safestack.h ../include/openssl/sha.h
clienthellotest.o: ../include/openssl/srtp.h ../include/openssl/ssl.h
clienthellotest.o: ../include/openssl/ssl2.h ../include/openssl/ssl23.h
clienthellotest.o: ../include/openssl/ssl3.h ../include/openssl/stack.h
clienthellotest.o: ../include/openssl/symhacks.h ../include/openssl/tls1.h
clienthellotest.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h
clienthellotest.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
clienthellotest.o: c:\mingw\include\ctype.h c:\mingw\include\dbt.h
clienthellotest.o: c:\mingw\include\errno.h c:\mingw\include\msvcrtver.h
clienthellotest.o: c:\mingw\include\mswsock.h c:\mingw\include\poppack.h
clienthellotest.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
clienthellotest.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
clienthellotest.o: c:\mingw\include\string.h c:\mingw\include\strings.h
clienthellotest.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
clienthellotest.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
clienthellotest.o: c:\mingw\include\wchar.h c:\mingw\include\wctype.h
clienthellotest.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
clienthellotest.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
clienthellotest.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
clienthellotest.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
clienthellotest.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
clienthellotest.o: c:\mingw\include\winsock.h c:\mingw\include\winsvc.h
clienthellotest.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
clienthellotest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
clienthellotest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
clienthellotest.o: clienthellotest.c
constant_time_test.o: ../crypto/constant_time_locl.h ../e_os.h
constant_time_test.o: ../include/openssl/e_os2.h
constant_time_test.o: ../include/openssl/opensslconf.h
constant_time_test.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
constant_time_test.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
constant_time_test.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
constant_time_test.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
constant_time_test.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
constant_time_test.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
constant_time_test.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
constant_time_test.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
constant_time_test.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
constant_time_test.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
constant_time_test.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
constant_time_test.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
constant_time_test.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
constant_time_test.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
constant_time_test.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
constant_time_test.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
constant_time_test.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
constant_time_test.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
constant_time_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
constant_time_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
constant_time_test.o: constant_time_test.c
destest.o: ../include/openssl/des.h ../include/openssl/des_old.h
destest.o: ../include/openssl/e_os2.h ../include/openssl/opensslconf.h
destest.o: ../include/openssl/ossl_typ.h ../include/openssl/safestack.h
destest.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
destest.o: ../include/openssl/ui.h ../include/openssl/ui_compat.h
destest.o: c:\mingw\include\_mingw.h c:\mingw\include\io.h
destest.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
destest.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
destest.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
destest.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
destest.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
destest.o: c:\mingw\include\wchar.h
destest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
destest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h destest.c
dhtest.o: ../e_os.h ../include/openssl/bio.h ../include/openssl/bn.h
dhtest.o: ../include/openssl/crypto.h ../include/openssl/dh.h
dhtest.o: ../include/openssl/e_os2.h ../include/openssl/err.h
dhtest.o: ../include/openssl/lhash.h ../include/openssl/opensslconf.h
dhtest.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
dhtest.o: ../include/openssl/rand.h ../include/openssl/safestack.h
dhtest.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
dhtest.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
dhtest.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
dhtest.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
dhtest.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
dhtest.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
dhtest.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
dhtest.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
dhtest.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
dhtest.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
dhtest.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
dhtest.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
dhtest.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
dhtest.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
dhtest.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
dhtest.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
dhtest.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
dhtest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
dhtest.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
dhtest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
dhtest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h dhtest.c
dsatest.o: ../e_os.h ../include/openssl/bio.h ../include/openssl/bn.h
dsatest.o: ../include/openssl/crypto.h ../include/openssl/dh.h
dsatest.o: ../include/openssl/dsa.h ../include/openssl/e_os2.h
dsatest.o: ../include/openssl/err.h ../include/openssl/lhash.h
dsatest.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
dsatest.o: ../include/openssl/ossl_typ.h ../include/openssl/rand.h
dsatest.o: ../include/openssl/safestack.h ../include/openssl/stack.h
dsatest.o: ../include/openssl/symhacks.h c:\mingw\include\_mingw.h
dsatest.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
dsatest.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
dsatest.o: c:\mingw\include\io.h c:\mingw\include\limits.h
dsatest.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
dsatest.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
dsatest.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
dsatest.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
dsatest.o: c:\mingw\include\string.h c:\mingw\include\strings.h
dsatest.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\stat.h
dsatest.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
dsatest.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
dsatest.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
dsatest.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
dsatest.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
dsatest.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
dsatest.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
dsatest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
dsatest.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
dsatest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
dsatest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h dsatest.c
dtlstest.o: ../include/openssl/asn1.h ../include/openssl/bio.h
dtlstest.o: ../include/openssl/buffer.h ../include/openssl/comp.h
dtlstest.o: ../include/openssl/crypto.h ../include/openssl/dtls1.h
dtlstest.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
dtlstest.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
dtlstest.o: ../include/openssl/err.h ../include/openssl/evp.h
dtlstest.o: ../include/openssl/hmac.h ../include/openssl/kssl.h
dtlstest.o: ../include/openssl/lhash.h ../include/openssl/obj_mac.h
dtlstest.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
dtlstest.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
dtlstest.o: ../include/openssl/pem.h ../include/openssl/pem2.h
dtlstest.o: ../include/openssl/pkcs7.h ../include/openssl/pqueue.h
dtlstest.o: ../include/openssl/safestack.h ../include/openssl/sha.h
dtlstest.o: ../include/openssl/srtp.h ../include/openssl/ssl.h
dtlstest.o: ../include/openssl/ssl2.h ../include/openssl/ssl23.h
dtlstest.o: ../include/openssl/ssl3.h ../include/openssl/stack.h
dtlstest.o: ../include/openssl/symhacks.h ../include/openssl/tls1.h
dtlstest.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h
dtlstest.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
dtlstest.o: c:\mingw\include\ctype.h c:\mingw\include\dbt.h
dtlstest.o: c:\mingw\include\errno.h c:\mingw\include\msvcrtver.h
dtlstest.o: c:\mingw\include\mswsock.h c:\mingw\include\poppack.h
dtlstest.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
dtlstest.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
dtlstest.o: c:\mingw\include\string.h c:\mingw\include\strings.h
dtlstest.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
dtlstest.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
dtlstest.o: c:\mingw\include\wchar.h c:\mingw\include\wctype.h
dtlstest.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
dtlstest.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
dtlstest.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
dtlstest.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
dtlstest.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
dtlstest.o: c:\mingw\include\winsock.h c:\mingw\include\winsvc.h
dtlstest.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
dtlstest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
dtlstest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h dtlstest.c
dtlstest.o: ssltestlib.h testutil.h
ecdhtest.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
ecdhtest.o: ../include/openssl/bn.h ../include/openssl/crypto.h
ecdhtest.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
ecdhtest.o: ../include/openssl/ecdh.h ../include/openssl/err.h
ecdhtest.o: ../include/openssl/lhash.h ../include/openssl/obj_mac.h
ecdhtest.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
ecdhtest.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
ecdhtest.o: ../include/openssl/rand.h ../include/openssl/safestack.h
ecdhtest.o: ../include/openssl/sha.h ../include/openssl/stack.h
ecdhtest.o: ../include/openssl/symhacks.h c:\mingw\include\_mingw.h
ecdhtest.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
ecdhtest.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
ecdhtest.o: c:\mingw\include\io.h c:\mingw\include\limits.h
ecdhtest.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
ecdhtest.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
ecdhtest.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
ecdhtest.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ecdhtest.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ecdhtest.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ecdhtest.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ecdhtest.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
ecdhtest.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
ecdhtest.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
ecdhtest.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
ecdhtest.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
ecdhtest.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
ecdhtest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
ecdhtest.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
ecdhtest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ecdhtest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ecdhtest.c
ecdsatest.o: ../include/openssl/asn1.h ../include/openssl/bio.h
ecdsatest.o: ../include/openssl/bn.h ../include/openssl/buffer.h
ecdsatest.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
ecdsatest.o: ../include/openssl/ec.h ../include/openssl/ecdh.h
ecdsatest.o: ../include/openssl/ecdsa.h ../include/openssl/engine.h
ecdsatest.o: ../include/openssl/err.h ../include/openssl/evp.h
ecdsatest.o: ../include/openssl/lhash.h ../include/openssl/obj_mac.h
ecdsatest.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
ecdsatest.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
ecdsatest.o: ../include/openssl/pkcs7.h ../include/openssl/rand.h
ecdsatest.o: ../include/openssl/safestack.h ../include/openssl/sha.h
ecdsatest.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
ecdsatest.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h
ecdsatest.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
ecdsatest.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
ecdsatest.o: c:\mingw\include\limits.h c:\mingw\include\msvcrtver.h
ecdsatest.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
ecdsatest.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
ecdsatest.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
ecdsatest.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
ecdsatest.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
ecdsatest.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
ecdsatest.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
ecdsatest.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
ecdsatest.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
ecdsatest.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
ecdsatest.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
ecdsatest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
ecdsatest.o: c:\mingw\include\winver.h
ecdsatest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ecdsatest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ecdsatest.c
ectest.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
ectest.o: ../include/openssl/bn.h ../include/openssl/buffer.h
ectest.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
ectest.o: ../include/openssl/ec.h ../include/openssl/ecdh.h
ectest.o: ../include/openssl/ecdsa.h ../include/openssl/engine.h
ectest.o: ../include/openssl/err.h ../include/openssl/evp.h
ectest.o: ../include/openssl/lhash.h ../include/openssl/obj_mac.h
ectest.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
ectest.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
ectest.o: ../include/openssl/pkcs7.h ../include/openssl/rand.h
ectest.o: ../include/openssl/safestack.h ../include/openssl/sha.h
ectest.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
ectest.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h
ectest.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
ectest.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
ectest.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
ectest.o: c:\mingw\include\limits.h c:\mingw\include\malloc.h
ectest.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
ectest.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
ectest.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
ectest.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
ectest.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
ectest.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
ectest.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
ectest.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
ectest.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
ectest.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
ectest.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
ectest.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
ectest.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
ectest.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
ectest.o: c:\mingw\include\ws2tcpip.h
ectest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ectest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ectest.c
enginetest.o: ../include/openssl/asn1.h ../include/openssl/bio.h
enginetest.o: ../include/openssl/buffer.h ../include/openssl/crypto.h
enginetest.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
enginetest.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
enginetest.o: ../include/openssl/engine.h ../include/openssl/err.h
enginetest.o: ../include/openssl/evp.h ../include/openssl/lhash.h
enginetest.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
enginetest.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
enginetest.o: ../include/openssl/ossl_typ.h ../include/openssl/pkcs7.h
enginetest.o: ../include/openssl/safestack.h ../include/openssl/sha.h
enginetest.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
enginetest.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h
enginetest.o: c:\mingw\include\_mingw.h c:\mingw\include\errno.h
enginetest.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
enginetest.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
enginetest.o: c:\mingw\include\string.h c:\mingw\include\strings.h
enginetest.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
enginetest.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
enginetest.o: c:\mingw\include\wchar.h
enginetest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
enginetest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h enginetest.c
evp_extra_test.o: ../include/openssl/asn1.h ../include/openssl/bio.h
evp_extra_test.o: ../include/openssl/buffer.h ../include/openssl/crypto.h
evp_extra_test.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
evp_extra_test.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
evp_extra_test.o: ../include/openssl/err.h ../include/openssl/evp.h
evp_extra_test.o: ../include/openssl/lhash.h ../include/openssl/obj_mac.h
evp_extra_test.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
evp_extra_test.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
evp_extra_test.o: ../include/openssl/pkcs7.h ../include/openssl/rsa.h
evp_extra_test.o: ../include/openssl/safestack.h ../include/openssl/sha.h
evp_extra_test.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
evp_extra_test.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h
evp_extra_test.o: c:\mingw\include\_mingw.h c:\mingw\include\errno.h
evp_extra_test.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
evp_extra_test.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
evp_extra_test.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
evp_extra_test.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
evp_extra_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
evp_extra_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
evp_extra_test.o: evp_extra_test.c
evp_test.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
evp_test.o: ../include/openssl/buffer.h ../include/openssl/conf.h
evp_test.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
evp_test.o: ../include/openssl/ec.h ../include/openssl/ecdh.h
evp_test.o: ../include/openssl/ecdsa.h ../include/openssl/engine.h
evp_test.o: ../include/openssl/err.h ../include/openssl/evp.h
evp_test.o: ../include/openssl/lhash.h ../include/openssl/obj_mac.h
evp_test.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
evp_test.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
evp_test.o: ../include/openssl/pkcs7.h ../include/openssl/safestack.h
evp_test.o: ../include/openssl/sha.h ../include/openssl/stack.h
evp_test.o: ../include/openssl/symhacks.h ../include/openssl/x509.h
evp_test.o: ../include/openssl/x509_vfy.h c:\mingw\include\_mingw.h
evp_test.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
evp_test.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
evp_test.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
evp_test.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
evp_test.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
evp_test.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
evp_test.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
evp_test.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
evp_test.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
evp_test.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
evp_test.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
evp_test.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
evp_test.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
evp_test.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
evp_test.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
evp_test.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
evp_test.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
evp_test.o: c:\mingw\include\ws2tcpip.h
evp_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
evp_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h evp_test.c
exptest.o: ../e_os.h ../include/openssl/bio.h ../include/openssl/bn.h
exptest.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
exptest.o: ../include/openssl/err.h ../include/openssl/lhash.h
exptest.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
exptest.o: ../include/openssl/ossl_typ.h ../include/openssl/rand.h
exptest.o: ../include/openssl/safestack.h ../include/openssl/stack.h
exptest.o: ../include/openssl/symhacks.h c:\mingw\include\_mingw.h
exptest.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
exptest.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
exptest.o: c:\mingw\include\io.h c:\mingw\include\limits.h
exptest.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
exptest.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
exptest.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
exptest.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
exptest.o: c:\mingw\include\string.h c:\mingw\include\strings.h
exptest.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
exptest.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
exptest.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
exptest.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
exptest.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
exptest.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
exptest.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
exptest.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
exptest.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
exptest.o: c:\mingw\include\ws2tcpip.h
exptest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
exptest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h exptest.c
heartbeat_test.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
heartbeat_test.o: ../include/openssl/buffer.h ../include/openssl/comp.h
heartbeat_test.o: ../include/openssl/crypto.h ../include/openssl/dsa.h
heartbeat_test.o: ../include/openssl/dtls1.h ../include/openssl/e_os2.h
heartbeat_test.o: ../include/openssl/ec.h ../include/openssl/ecdh.h
heartbeat_test.o: ../include/openssl/ecdsa.h ../include/openssl/err.h
heartbeat_test.o: ../include/openssl/evp.h ../include/openssl/hmac.h
heartbeat_test.o: ../include/openssl/kssl.h ../include/openssl/lhash.h
heartbeat_test.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
heartbeat_test.o: ../include/openssl/opensslconf.h
heartbeat_test.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
heartbeat_test.o: ../include/openssl/pem.h ../include/openssl/pem2.h
heartbeat_test.o: ../include/openssl/pkcs7.h ../include/openssl/pqueue.h
heartbeat_test.o: ../include/openssl/rsa.h ../include/openssl/safestack.h
heartbeat_test.o: ../include/openssl/sha.h ../include/openssl/srtp.h
heartbeat_test.o: ../include/openssl/ssl.h ../include/openssl/ssl2.h
heartbeat_test.o: ../include/openssl/ssl23.h ../include/openssl/ssl3.h
heartbeat_test.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
heartbeat_test.o: ../include/openssl/tls1.h ../include/openssl/x509.h
heartbeat_test.o: ../include/openssl/x509_vfy.h ../ssl/ssl_locl.h
heartbeat_test.o: ../test/testutil.h c:\mingw\include\_mingw.h
heartbeat_test.o: c:\mingw\include\basetsd.h c:\mingw\include\ctype.h
heartbeat_test.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
heartbeat_test.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
heartbeat_test.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
heartbeat_test.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
heartbeat_test.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
heartbeat_test.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
heartbeat_test.o: c:\mingw\include\string.h c:\mingw\include\strings.h
heartbeat_test.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
heartbeat_test.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
heartbeat_test.o: c:\mingw\include\wchar.h c:\mingw\include\wctype.h
heartbeat_test.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
heartbeat_test.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
heartbeat_test.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
heartbeat_test.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
heartbeat_test.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
heartbeat_test.o: c:\mingw\include\winsock.h c:\mingw\include\winsock2.h
heartbeat_test.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
heartbeat_test.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
heartbeat_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
heartbeat_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
heartbeat_test.o: heartbeat_test.c
hmactest.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
hmactest.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
hmactest.o: ../include/openssl/evp.h ../include/openssl/hmac.h
hmactest.o: ../include/openssl/md5.h ../include/openssl/obj_mac.h
hmactest.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
hmactest.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
hmactest.o: ../include/openssl/safestack.h ../include/openssl/stack.h
hmactest.o: ../include/openssl/symhacks.h c:\mingw\include\_mingw.h
hmactest.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
hmactest.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
hmactest.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
hmactest.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
hmactest.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
hmactest.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
hmactest.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
hmactest.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
hmactest.o: c:\mingw\include\sys\types.h c:\mingw\include\time.h
hmactest.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
hmactest.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
hmactest.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
hmactest.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
hmactest.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
hmactest.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
hmactest.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
hmactest.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
hmactest.o: c:\mingw\include\ws2tcpip.h
hmactest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
hmactest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h hmactest.c
ideatest.o: ../e_os.h ../include/openssl/e_os2.h
ideatest.o: ../include/openssl/opensslconf.h c:\mingw\include\_mingw.h
ideatest.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
ideatest.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
ideatest.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
ideatest.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
ideatest.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
ideatest.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
ideatest.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
ideatest.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
ideatest.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
ideatest.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
ideatest.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
ideatest.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
ideatest.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
ideatest.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
ideatest.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
ideatest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
ideatest.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
ideatest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ideatest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ideatest.c
igetest.o: ../include/openssl/aes.h ../include/openssl/e_os2.h
igetest.o: ../include/openssl/opensslconf.h ../include/openssl/ossl_typ.h
igetest.o: ../include/openssl/rand.h c:\mingw\include\_mingw.h
igetest.o: c:\mingw\include\assert.h c:\mingw\include\basetsd.h
igetest.o: c:\mingw\include\dbt.h c:\mingw\include\msvcrtver.h
igetest.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
igetest.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
igetest.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
igetest.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
igetest.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
igetest.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
igetest.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
igetest.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
igetest.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
igetest.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
igetest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
igetest.o: c:\mingw\include\winver.h
igetest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
igetest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h igetest.c
jpaketest.o: ../include/openssl/buffer.h ../include/openssl/crypto.h
jpaketest.o: ../include/openssl/e_os2.h ../include/openssl/opensslconf.h
jpaketest.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
jpaketest.o: ../include/openssl/safestack.h ../include/openssl/stack.h
jpaketest.o: ../include/openssl/symhacks.h c:\mingw\include\_mingw.h
jpaketest.o: c:\mingw\include\ctype.h c:\mingw\include\msvcrtver.h
jpaketest.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
jpaketest.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
jpaketest.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
jpaketest.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
jpaketest.o: c:\mingw\include\wchar.h c:\mingw\include\wctype.h
jpaketest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
jpaketest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h jpaketest.c
md2test.o: ../include/openssl/buffer.h ../include/openssl/crypto.h
md2test.o: ../include/openssl/e_os2.h ../include/openssl/opensslconf.h
md2test.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
md2test.o: ../include/openssl/safestack.h ../include/openssl/stack.h
md2test.o: ../include/openssl/symhacks.h c:\mingw\include\_mingw.h
md2test.o: c:\mingw\include\ctype.h c:\mingw\include\msvcrtver.h
md2test.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
md2test.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
md2test.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
md2test.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
md2test.o: c:\mingw\include\wchar.h c:\mingw\include\wctype.h
md2test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
md2test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h md2test.c
md4test.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
md4test.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
md4test.o: ../include/openssl/evp.h ../include/openssl/md4.h
md4test.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
md4test.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
md4test.o: ../include/openssl/ossl_typ.h ../include/openssl/safestack.h
md4test.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
md4test.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
md4test.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
md4test.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
md4test.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
md4test.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
md4test.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
md4test.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
md4test.o: c:\mingw\include\string.h c:\mingw\include\strings.h
md4test.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
md4test.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
md4test.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
md4test.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
md4test.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
md4test.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
md4test.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
md4test.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
md4test.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
md4test.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
md4test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
md4test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h md4test.c
md5test.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
md5test.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
md5test.o: ../include/openssl/evp.h ../include/openssl/md5.h
md5test.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
md5test.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
md5test.o: ../include/openssl/ossl_typ.h ../include/openssl/safestack.h
md5test.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
md5test.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
md5test.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
md5test.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
md5test.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
md5test.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
md5test.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
md5test.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
md5test.o: c:\mingw\include\string.h c:\mingw\include\strings.h
md5test.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
md5test.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
md5test.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
md5test.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
md5test.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
md5test.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
md5test.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
md5test.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
md5test.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
md5test.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
md5test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
md5test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h md5test.c
mdc2test.o: ../e_os.h ../include/openssl/e_os2.h
mdc2test.o: ../include/openssl/opensslconf.h c:\mingw\include\_mingw.h
mdc2test.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
mdc2test.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
mdc2test.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
mdc2test.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
mdc2test.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
mdc2test.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
mdc2test.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
mdc2test.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
mdc2test.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
mdc2test.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
mdc2test.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
mdc2test.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
mdc2test.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
mdc2test.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
mdc2test.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
mdc2test.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
mdc2test.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
mdc2test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
mdc2test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h mdc2test.c
randtest.o: ../e_os.h ../include/openssl/e_os2.h
randtest.o: ../include/openssl/opensslconf.h ../include/openssl/ossl_typ.h
randtest.o: ../include/openssl/rand.h c:\mingw\include\_mingw.h
randtest.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
randtest.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
randtest.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
randtest.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
randtest.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
randtest.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
randtest.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
randtest.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
randtest.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
randtest.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
randtest.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
randtest.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
randtest.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
randtest.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
randtest.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
randtest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
randtest.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
randtest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
randtest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h randtest.c
rc2test.o: ../e_os.h ../include/openssl/e_os2.h
rc2test.o: ../include/openssl/opensslconf.h ../include/openssl/rc2.h
rc2test.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
rc2test.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
rc2test.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
rc2test.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
rc2test.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
rc2test.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
rc2test.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
rc2test.o: c:\mingw\include\string.h c:\mingw\include\strings.h
rc2test.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
rc2test.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
rc2test.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
rc2test.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
rc2test.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
rc2test.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
rc2test.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
rc2test.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
rc2test.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
rc2test.o: c:\mingw\include\ws2tcpip.h
rc2test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rc2test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rc2test.c
rc4test.o: ../e_os.h ../include/openssl/e_os2.h
rc4test.o: ../include/openssl/opensslconf.h ../include/openssl/rc4.h
rc4test.o: ../include/openssl/sha.h c:\mingw\include\_mingw.h
rc4test.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
rc4test.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
rc4test.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
rc4test.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
rc4test.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
rc4test.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
rc4test.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
rc4test.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
rc4test.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
rc4test.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
rc4test.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
rc4test.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
rc4test.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
rc4test.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
rc4test.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
rc4test.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
rc4test.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
rc4test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rc4test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rc4test.c
rc5test.o: ../include/openssl/buffer.h ../include/openssl/crypto.h
rc5test.o: ../include/openssl/e_os2.h ../include/openssl/opensslconf.h
rc5test.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
rc5test.o: ../include/openssl/safestack.h ../include/openssl/stack.h
rc5test.o: ../include/openssl/symhacks.h c:\mingw\include\_mingw.h
rc5test.o: c:\mingw\include\ctype.h c:\mingw\include\msvcrtver.h
rc5test.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
rc5test.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
rc5test.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
rc5test.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
rc5test.o: c:\mingw\include\wchar.h c:\mingw\include\wctype.h
rc5test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rc5test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rc5test.c
rmdtest.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
rmdtest.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
rmdtest.o: ../include/openssl/evp.h ../include/openssl/obj_mac.h
rmdtest.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
rmdtest.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
rmdtest.o: ../include/openssl/ripemd.h ../include/openssl/safestack.h
rmdtest.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
rmdtest.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
rmdtest.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
rmdtest.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
rmdtest.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
rmdtest.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
rmdtest.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
rmdtest.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
rmdtest.o: c:\mingw\include\string.h c:\mingw\include\strings.h
rmdtest.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
rmdtest.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
rmdtest.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
rmdtest.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
rmdtest.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
rmdtest.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
rmdtest.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
rmdtest.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
rmdtest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
rmdtest.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
rmdtest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rmdtest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rmdtest.c
rsa_test.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
rsa_test.o: ../include/openssl/bn.h ../include/openssl/crypto.h
rsa_test.o: ../include/openssl/e_os2.h ../include/openssl/err.h
rsa_test.o: ../include/openssl/lhash.h ../include/openssl/opensslconf.h
rsa_test.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
rsa_test.o: ../include/openssl/rand.h ../include/openssl/rsa.h
rsa_test.o: ../include/openssl/safestack.h ../include/openssl/stack.h
rsa_test.o: ../include/openssl/symhacks.h c:\mingw\include\_mingw.h
rsa_test.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
rsa_test.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
rsa_test.o: c:\mingw\include\io.h c:\mingw\include\limits.h
rsa_test.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
rsa_test.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
rsa_test.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
rsa_test.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
rsa_test.o: c:\mingw\include\string.h c:\mingw\include\strings.h
rsa_test.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
rsa_test.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
rsa_test.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
rsa_test.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
rsa_test.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
rsa_test.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
rsa_test.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
rsa_test.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
rsa_test.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
rsa_test.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
rsa_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
rsa_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h rsa_test.c
sha1test.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
sha1test.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
sha1test.o: ../include/openssl/evp.h ../include/openssl/obj_mac.h
sha1test.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
sha1test.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
sha1test.o: ../include/openssl/safestack.h ../include/openssl/sha.h
sha1test.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
sha1test.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
sha1test.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
sha1test.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
sha1test.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
sha1test.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
sha1test.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
sha1test.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
sha1test.o: c:\mingw\include\string.h c:\mingw\include\strings.h
sha1test.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
sha1test.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
sha1test.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
sha1test.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
sha1test.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
sha1test.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
sha1test.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
sha1test.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
sha1test.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
sha1test.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
sha1test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
sha1test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h sha1test.c
shatest.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
shatest.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
shatest.o: ../include/openssl/evp.h ../include/openssl/obj_mac.h
shatest.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
shatest.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
shatest.o: ../include/openssl/safestack.h ../include/openssl/sha.h
shatest.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
shatest.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
shatest.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
shatest.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
shatest.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
shatest.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
shatest.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
shatest.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
shatest.o: c:\mingw\include\string.h c:\mingw\include\strings.h
shatest.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
shatest.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
shatest.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
shatest.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
shatest.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
shatest.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
shatest.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
shatest.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
shatest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
shatest.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
shatest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
shatest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h shatest.c
srptest.o: ../include/openssl/bio.h ../include/openssl/bn.h
srptest.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
srptest.o: ../include/openssl/err.h ../include/openssl/lhash.h
srptest.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
srptest.o: ../include/openssl/ossl_typ.h ../include/openssl/rand.h
srptest.o: ../include/openssl/safestack.h ../include/openssl/srp.h
srptest.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
srptest.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
srptest.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
srptest.o: c:\mingw\include\limits.h c:\mingw\include\msvcrtver.h
srptest.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
srptest.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
srptest.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
srptest.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
srptest.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
srptest.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
srptest.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
srptest.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
srptest.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
srptest.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
srptest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
srptest.o: c:\mingw\include\winver.h
srptest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
srptest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h srptest.c
ssltest.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
ssltest.o: ../include/openssl/bn.h ../include/openssl/buffer.h
ssltest.o: ../include/openssl/comp.h ../include/openssl/conf.h
ssltest.o: ../include/openssl/crypto.h ../include/openssl/dh.h
ssltest.o: ../include/openssl/dsa.h ../include/openssl/dtls1.h
ssltest.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
ssltest.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
ssltest.o: ../include/openssl/engine.h ../include/openssl/err.h
ssltest.o: ../include/openssl/evp.h ../include/openssl/hmac.h
ssltest.o: ../include/openssl/kssl.h ../include/openssl/lhash.h
ssltest.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
ssltest.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
ssltest.o: ../include/openssl/ossl_typ.h ../include/openssl/pem.h
ssltest.o: ../include/openssl/pem2.h ../include/openssl/pkcs7.h
ssltest.o: ../include/openssl/pqueue.h ../include/openssl/rand.h
ssltest.o: ../include/openssl/rsa.h ../include/openssl/safestack.h
ssltest.o: ../include/openssl/sha.h ../include/openssl/srp.h
ssltest.o: ../include/openssl/srtp.h ../include/openssl/ssl.h
ssltest.o: ../include/openssl/ssl2.h ../include/openssl/ssl23.h
ssltest.o: ../include/openssl/ssl3.h ../include/openssl/stack.h
ssltest.o: ../include/openssl/symhacks.h ../include/openssl/tls1.h
ssltest.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h
ssltest.o: ../include/openssl/x509v3.h c:\mingw\include\_mingw.h
ssltest.o: c:\mingw\include\assert.h c:\mingw\include\basetsd.h
ssltest.o: c:\mingw\include\ctype.h c:\mingw\include\dbt.h
ssltest.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
ssltest.o: c:\mingw\include\io.h c:\mingw\include\limits.h
ssltest.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
ssltest.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
ssltest.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
ssltest.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ssltest.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ssltest.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ssltest.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ssltest.o: c:\mingw\include\wchar.h c:\mingw\include\wctype.h
ssltest.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
ssltest.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
ssltest.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
ssltest.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
ssltest.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
ssltest.o: c:\mingw\include\winsock.h c:\mingw\include\winsock2.h
ssltest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
ssltest.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
ssltest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ssltest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ssltest.c
ssltestlib.o: ../include/openssl/asn1.h ../include/openssl/bio.h
ssltestlib.o: ../include/openssl/buffer.h ../include/openssl/comp.h
ssltestlib.o: ../include/openssl/crypto.h ../include/openssl/dtls1.h
ssltestlib.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
ssltestlib.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
ssltestlib.o: ../include/openssl/evp.h ../include/openssl/hmac.h
ssltestlib.o: ../include/openssl/kssl.h ../include/openssl/lhash.h
ssltestlib.o: ../include/openssl/obj_mac.h ../include/openssl/objects.h
ssltestlib.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
ssltestlib.o: ../include/openssl/ossl_typ.h ../include/openssl/pem.h
ssltestlib.o: ../include/openssl/pem2.h ../include/openssl/pkcs7.h
ssltestlib.o: ../include/openssl/pqueue.h ../include/openssl/safestack.h
ssltestlib.o: ../include/openssl/sha.h ../include/openssl/srtp.h
ssltestlib.o: ../include/openssl/ssl.h ../include/openssl/ssl2.h
ssltestlib.o: ../include/openssl/ssl23.h ../include/openssl/ssl3.h
ssltestlib.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
ssltestlib.o: ../include/openssl/tls1.h ../include/openssl/x509.h
ssltestlib.o: ../include/openssl/x509_vfy.h c:\mingw\include\_mingw.h
ssltestlib.o: c:\mingw\include\basetsd.h c:\mingw\include\ctype.h
ssltestlib.o: c:\mingw\include\dbt.h c:\mingw\include\msvcrtver.h
ssltestlib.o: c:\mingw\include\mswsock.h c:\mingw\include\poppack.h
ssltestlib.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
ssltestlib.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
ssltestlib.o: c:\mingw\include\string.h c:\mingw\include\strings.h
ssltestlib.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
ssltestlib.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
ssltestlib.o: c:\mingw\include\wchar.h c:\mingw\include\wctype.h
ssltestlib.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
ssltestlib.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
ssltestlib.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
ssltestlib.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
ssltestlib.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
ssltestlib.o: c:\mingw\include\winsock.h c:\mingw\include\winsvc.h
ssltestlib.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
ssltestlib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
ssltestlib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h ssltestlib.c
ssltestlib.o: ssltestlib.h
sslv2conftest.o: ../include/openssl/asn1.h ../include/openssl/bio.h
sslv2conftest.o: ../include/openssl/buffer.h ../include/openssl/comp.h
sslv2conftest.o: ../include/openssl/crypto.h ../include/openssl/dtls1.h
sslv2conftest.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
sslv2conftest.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
sslv2conftest.o: ../include/openssl/err.h ../include/openssl/evp.h
sslv2conftest.o: ../include/openssl/hmac.h ../include/openssl/kssl.h
sslv2conftest.o: ../include/openssl/lhash.h ../include/openssl/obj_mac.h
sslv2conftest.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
sslv2conftest.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
sslv2conftest.o: ../include/openssl/pem.h ../include/openssl/pem2.h
sslv2conftest.o: ../include/openssl/pkcs7.h ../include/openssl/pqueue.h
sslv2conftest.o: ../include/openssl/safestack.h ../include/openssl/sha.h
sslv2conftest.o: ../include/openssl/srtp.h ../include/openssl/ssl.h
sslv2conftest.o: ../include/openssl/ssl2.h ../include/openssl/ssl23.h
sslv2conftest.o: ../include/openssl/ssl3.h ../include/openssl/stack.h
sslv2conftest.o: ../include/openssl/symhacks.h ../include/openssl/tls1.h
sslv2conftest.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h
sslv2conftest.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
sslv2conftest.o: c:\mingw\include\ctype.h c:\mingw\include\dbt.h
sslv2conftest.o: c:\mingw\include\errno.h c:\mingw\include\msvcrtver.h
sslv2conftest.o: c:\mingw\include\mswsock.h c:\mingw\include\poppack.h
sslv2conftest.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
sslv2conftest.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
sslv2conftest.o: c:\mingw\include\string.h c:\mingw\include\strings.h
sslv2conftest.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
sslv2conftest.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
sslv2conftest.o: c:\mingw\include\wchar.h c:\mingw\include\wctype.h
sslv2conftest.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
sslv2conftest.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
sslv2conftest.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
sslv2conftest.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
sslv2conftest.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
sslv2conftest.o: c:\mingw\include\winsock.h c:\mingw\include\winsvc.h
sslv2conftest.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
sslv2conftest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
sslv2conftest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
sslv2conftest.o: sslv2conftest.c
v3nametest.o: ../e_os.h ../include/openssl/asn1.h ../include/openssl/bio.h
v3nametest.o: ../include/openssl/buffer.h ../include/openssl/conf.h
v3nametest.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
v3nametest.o: ../include/openssl/ec.h ../include/openssl/ecdh.h
v3nametest.o: ../include/openssl/ecdsa.h ../include/openssl/evp.h
v3nametest.o: ../include/openssl/lhash.h ../include/openssl/obj_mac.h
v3nametest.o: ../include/openssl/objects.h ../include/openssl/opensslconf.h
v3nametest.o: ../include/openssl/opensslv.h ../include/openssl/ossl_typ.h
v3nametest.o: ../include/openssl/pkcs7.h ../include/openssl/safestack.h
v3nametest.o: ../include/openssl/sha.h ../include/openssl/stack.h
v3nametest.o: ../include/openssl/symhacks.h ../include/openssl/x509.h
v3nametest.o: ../include/openssl/x509_vfy.h ../include/openssl/x509v3.h
v3nametest.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
v3nametest.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
v3nametest.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
v3nametest.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
v3nametest.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
v3nametest.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
v3nametest.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
v3nametest.o: c:\mingw\include\string.h c:\mingw\include\strings.h
v3nametest.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
v3nametest.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
v3nametest.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
v3nametest.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
v3nametest.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
v3nametest.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
v3nametest.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
v3nametest.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
v3nametest.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
v3nametest.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
v3nametest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
v3nametest.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h v3nametest.c
verify_extra_test.o: ../include/openssl/asn1.h ../include/openssl/bio.h
verify_extra_test.o: ../include/openssl/buffer.h ../include/openssl/crypto.h
verify_extra_test.o: ../include/openssl/e_os2.h ../include/openssl/ec.h
verify_extra_test.o: ../include/openssl/ecdh.h ../include/openssl/ecdsa.h
verify_extra_test.o: ../include/openssl/err.h ../include/openssl/evp.h
verify_extra_test.o: ../include/openssl/lhash.h ../include/openssl/obj_mac.h
verify_extra_test.o: ../include/openssl/objects.h
verify_extra_test.o: ../include/openssl/opensslconf.h
verify_extra_test.o: ../include/openssl/opensslv.h
verify_extra_test.o: ../include/openssl/ossl_typ.h ../include/openssl/pem.h
verify_extra_test.o: ../include/openssl/pem2.h ../include/openssl/pkcs7.h
verify_extra_test.o: ../include/openssl/safestack.h ../include/openssl/sha.h
verify_extra_test.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
verify_extra_test.o: ../include/openssl/x509.h ../include/openssl/x509_vfy.h
verify_extra_test.o: c:\mingw\include\_mingw.h c:\mingw\include\errno.h
verify_extra_test.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
verify_extra_test.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
verify_extra_test.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
verify_extra_test.o: c:\mingw\include\time.h c:\mingw\include\w32api.h
verify_extra_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
verify_extra_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
verify_extra_test.o: verify_extra_test.c
wp_test.o: ../include/openssl/crypto.h ../include/openssl/e_os2.h
wp_test.o: ../include/openssl/opensslconf.h ../include/openssl/opensslv.h
wp_test.o: ../include/openssl/ossl_typ.h ../include/openssl/safestack.h
wp_test.o: ../include/openssl/stack.h ../include/openssl/symhacks.h
wp_test.o: ../include/openssl/whrlpool.h c:\mingw\include\_mingw.h
wp_test.o: c:\mingw\include\msvcrtver.h c:\mingw\include\sdkddkver.h
wp_test.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
wp_test.o: c:\mingw\include\string.h c:\mingw\include\strings.h
wp_test.o: c:\mingw\include\sys/types.h c:\mingw\include\w32api.h
wp_test.o: c:\mingw\include\wchar.h
wp_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
wp_test.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h wp_test.c
