#!/bin/bash

TESTDIR=/tmp/oslib-test
EXE=unknown

die () {
	echo "$*" >&2
	exit -1
}

if [ -f test ] ; then
	EXE=test
elif [ -f test.exe ] ; then
	EXE=test.exe
else
	die Cannot find test or test.exe. Are you not in the output directory?
fi 

rm -rf $TESTDIR || die Failed to remove $TESTDIR
mkdir $TESTDIR || die Failed to mkdir $TESTDIR
cp $EXE $TESTDIR || die Failed to copy $EXE to $TESTDIR
cd $TESTDIR

touch testfile1.a
touch testfile2.a
touch testfile3.b
touch testfile4.b
touch testfile5

mkdir testdir1

./test || echo TEST FAILED

cd
rm -rf $TESTDIR