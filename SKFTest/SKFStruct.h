#include "WinDef.h"
#include "WinBase.h"

typedef HANDLE DEVHANDLE;
typedef HANDLE HAPPLICATION;
typedef HANDLE HCONTAINER;
#define MAX_IV_LEN 32
typedef struct Struct_Version{ 
	BYTE major;
	BYTE minor;
}VERSION;
typedef struct Struct_DEVINFO{
	VERSION	Version;
	CHAR	Manufacturer[64]; CHAR	Issuer[64];
	CHAR	Label[32];
	CHAR	SerialNumber[32]; VERSION	HWVersion;
	VERSION	FirmwareVersion; ULONG	AlgSymCap;
	ULONG	AlgAsymCap; ULONG	AlgHashCap; ULONG	DevAuthAlgId; ULONG	TotalSpace; ULONG	FreeSpace; BYTE	Reserved[64];
}DEVINFO,*PDEVINFO;

typedef struct Struct_BLOCKCIPHERPARAM{
		BYTE IV[MAX_IV_LEN];	//��ʼ����			
		ULONG IVLen;			//��ʼ����ʵ�ʳ��ȣ����ֽڼ��㣩
		ULONG PaddingType;		//��䷽ʽ��0��ʾ����䣬1��ʾ����PKCS#5��ʽ�������
		ULONG FeedBitLen;		//����ֵ��λ���ȣ���λ���㣩ֻ���OFB��CFBģʽ
	} BLOCKCIPHERPARAM, *PBLOCKCIPHERPARAM;

//device manage
//enumeric device
typedef ULONG (_stdcall *SKF_EnumDev)(BOOL bPresent, LPSTR szNameList, ULONG *pulSize);
//connect device
typedef ULONG (_stdcall *SKF_ConnectDev)(LPSTR szDevName, DEVHANDLE *phDev);
//disconnect device
typedef ULONG (_stdcall *SKF_DisConnectDev)(DEVHANDLE devHandle);
//get dev status
typedef ULONG (_stdcall *SKF_GetDevState)(LPSTR szDevName,ULONG *pulDevState);
//set dev label
typedef ULONG (_stdcall *SKF_SetLabel)(DEVHANDLE devHandle,LPSTR szLabel);
//get dev info
typedef ULONG (_stdcall *SKF_GetDevInfo)(DEVHANDLE devHandle,DEVINFO* szLabel);
//lock dev-not test
typedef ULONG (_stdcall *SKF_LockDev)(DEVHANDLE devHandle,ULONG ulTimeOut);
//unlock dev-not test
typedef ULONG (_stdcall *SKF_UnlockDev)(DEVHANDLE devHandle);
//unlock dev-not test
typedef ULONG (_stdcall *SKF_Transmit)(DEVHANDLE devHandle,BYTE* pbCommand,ULONG ulCommandLen,BYTE* pbData,ULONG* plDataLen);
//device manage end

//access control
//dev auth
typedef ULONG (_stdcall *SKF_DevAuth)(DEVHANDLE devHandle,BYTE* pbAuthData,ULONG ulLen);
//change dev auth key-not test
typedef ULONG (_stdcall *SKF_ChangeDevAuthKey)(DEVHANDLE devHandle,BYTE* pbKeyValue,ULONG ulLen);
//access control end

//crypto service
//gen random
typedef ULONG (_stdcall *SKF_GenRandom)(DEVHANDLE devHandle,BYTE* pbRandom,ULONG ulRandomLen);
//set symm key
typedef ULONG (_stdcall *SKF_SetSymmKey)(DEVHANDLE devHandle,unsigned char* pcKey,int encryptMethod,HANDLE* hkey);

//crypto service end