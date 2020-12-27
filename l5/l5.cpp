#include <Windows.h>
#include <wincrypt.h>
#include <iostream>

using namespace std;

int main()
{
	HCRYPTPROV cryptDesk,testDesk;
	HCRYPTHASH hashDesk;
	CryptAcquireContext(&cryptDesk, NULL, NULL, PROV_RSA_SCHANNEL, CRYPT_VERIFYCONTEXT);
	CryptAcquireContext(&testDesk, 0, 0, PROV_RSA_FULL, 0);
	BYTE DATA[100];
	DWORD DATAsize;
	cout << "Enter data size" << endl;
	cin >> DATAsize;
	//CryptGenRandom(cryptDesk, DATAsize, DATA);
	for (int i = 0; i < DATAsize; i++) DATA[i] = i;
	for (int i = 0; i < DATAsize; i++) cout << hex<<int(DATA[i]);
	cout << endl;
	CryptCreateHash(testDesk, CALG_MD5, 0, 0, &hashDesk);
	if (!CryptHashData(hashDesk, DATA,DATAsize, 0)) cout << "1     " << GetLastError() << endl;
	cout << hashDesk << endl;
	DWORD hashSize=100;
	BYTE hashDATA[100];
	if (!CryptGetHashParam(hashDesk, HP_HASHVAL, hashDATA, &hashSize, 0)) cout << "GHP1     " << GetLastError() << endl;
	for (int i = 0; i < hashSize; i++) cout << hex<<int(hashDATA[i]);
	cout << endl;
}

