#ifndef __SKF_H__
#define __SKF_H__

#ifdef __cplusplus
extern "C" {
#endif

//define ����
#define DEVAPI __stdcall

#define TRUE  1
#define FALSE 0
#define ADMIN_TYPE  0
#define USER_TYPE   1

#define SECURE_NEVER_ACCOUNT  0x00000000 //������
#define SECURE_ADM_ACCOUNT    0x00000001 //����ԱȨ��
#define SECURE_USER_ACCOUNT   0x00000010 //�û�Ȩ��
#define SECURE_ANYONE_ACCOUNT 0x000000FF //�κ���

#define DEV_ABSENT_STATE	0x00000000  //�豸������
#define DEV_PRESENT_STATE	0x00000001  //�豸����
#define DEV_UNKNOW_STATE	0x00000002  //�豸״̬δ֪


#define MAX_RSA_MODULUS_LEN  256			//Ϊ�㷨ģ������󳤶�
#define MAX_RSA_EXPONENT_LEN 4				//Ϊ�㷨ָ�������
#define ECC_MAX_XCOORDINATE_BITS_LEN 512	//ΪECC�㷨X�������󳤶�
#define ECC_MAX_YCOORDINATE_BITS_LEN 512	//ΪECC�㷨Y�������󳤶�
#define ECC_MAX_MODULUS_BITS_LEN 512		//ΪECC�㷨ģ������󳤶�
#define MAX_IV_LEN 32						//Ϊ��ʼ����������󳤶�

	typedef  signed char 	INT8;
	typedef  signed short   INT16;
	typedef  signed int		INT32;
	typedef  unsigned char 	UINT8;
	typedef  unsigned short UINT16;
	typedef  unsigned int   UINT32;
	typedef  int            BOOL;

	typedef unsigned char	BYTE;
	typedef signed short	SHORT;
	typedef unsigned short	USHORT;
	typedef unsigned int	UINT;
	typedef unsigned short	WORD;
	typedef char			CHAR;
	typedef unsigned char	UCHAR;
	typedef signed long		LONG;
	typedef unsigned long	ULONG;
	typedef unsigned long	DWORD;

	typedef UINT32	FLAGS;
 	typedef CHAR *	LPSTR;
	typedef void *	HANDLE;
	typedef HANDLE	DEVHANDLE;
	typedef HANDLE	HAPPLICATION;
	typedef HANDLE	HCONTAINER;


	typedef struct Struct_Version{
		BYTE major;
		BYTE minor;
	}VERSION;

	typedef struct Struct_DEVINFO{
		VERSION Version;              // �汾��,���ݽṹ�汾�ţ����ṹ�İ汾��Ϊ1.0
		CHAR Manufacturer[64];        // �豸������Ϣ,�ԡ�\0��Ϊ��������ASCII�ַ���
		CHAR Issuer[64];              // ���г�����Ϣ,�ԡ�\0��Ϊ��������ASCII�ַ���
		CHAR Label[32];				  // �豸��ǩ,�ԡ�\0��Ϊ��������ASCII�ַ���
		CHAR SerialNumber[32];        // ���к�,�ԡ�\0��Ϊ��������ASCII�ַ���
		VERSION HWVersion;            // �豸Ӳ���汾
		VERSION FirmwareVersion;      // �豸����̼��汾
		ULONG AlgSymCap;              // ���������㷨��ʶ
		ULONG AlgAsymCap;             // �ǶԳ������㷨��ʶ
		ULONG AlgHashCap;             // �����Ӵ��㷨��ʶ
		ULONG DevAuthAlgId;           // �豸��֤ʹ�õķ��������㷨��ʶ
		ULONG TotalSpace;             // �豸�ܿռ��С
		ULONG FreeSpace;              // �û����ÿռ��С 
		ULONG MaxECCBufferSize;       // �ܹ������ECC�������ݴ�С
		ULONG MaxBufferSize;          // �ܹ�����ķ���������Ӵ���������ݴ�С
		BYTE Reserved[64];            // ������չ
	}DEVINFO,*PDEVINFO;

	typedef struct Struct_RSAPUBLICKEYBLOB{
		ULONG AlgID;								//�㷨��ʶ��
		ULONG BitLen;								//ģ����ʵ��λ����,������8�ı���
		BYTE Modulus[MAX_RSA_MODULUS_LEN];			//ģ��n = p * q
		BYTE PublicExponent[MAX_RSA_EXPONENT_LEN];	//������Կe
	}RSAPUBLICKEYBLOB, *PRSAPUBLICKEYBLOB;

	typedef struct Struct_RSAPRIVATEKEYBLOB{
		ULONG AlgID;								//�㷨��ʶ��
		ULONG BitLen;								//ģ����ʵ��λ����
		BYTE Modulus[MAX_RSA_MODULUS_LEN];			//ģ��n = p * q
		BYTE PublicExponent[MAX_RSA_EXPONENT_LEN];	//������Կe
		BYTE PrivateExponent[MAX_RSA_MODULUS_LEN];	//˽����Կd
		BYTE Prime1[MAX_RSA_MODULUS_LEN/2];			//����p
		BYTE Prime2[MAX_RSA_MODULUS_LEN/2];			//����q
		BYTE Prime1Exponent[MAX_RSA_MODULUS_LEN/2];	//d mod (p-1)��ֵ
		BYTE Prime2Exponent[MAX_RSA_MODULUS_LEN/2];	//d mod (q -1)��ֵ
		BYTE Coefficient[MAX_RSA_MODULUS_LEN/2];	//qģp�ĳ˷���Ԫ
	}RSAPRIVATEKEYBLOB, *PRSAPRIVATEKEYBLOB;

	typedef struct Struct_RSAPARAMETERS
	{
		BYTE PrivateExponent[MAX_RSA_MODULUS_LEN];
		BYTE Prime1[MAX_RSA_MODULUS_LEN/2];
		BYTE Prime2[MAX_RSA_MODULUS_LEN/2];
		BYTE Prime1Exponent[MAX_RSA_MODULUS_LEN/2];
		BYTE Prime2Exponent[MAX_RSA_MODULUS_LEN/2];	
		BYTE Coefficient[MAX_RSA_MODULUS_LEN/2];
		BYTE Modulus[MAX_RSA_MODULUS_LEN];
		BYTE PublicExponent[MAX_RSA_EXPONENT_LEN];
	}RSAPARAMETERS, *PRSAPARAMETERS;


	typedef struct Struct_ECCPRIVATEKEYBLOB{
		ULONG BitLen;										//ģ����ʵ��λ����
		BYTE PrivateKey[ECC_MAX_MODULUS_BITS_LEN/8];		//˽����Կ
	}ECCPRIVATEKEYBLOB, *PECCPRIVATEKEYBLOB;

	typedef struct Struct_ECCPUBLICKEYBLOB{
		ULONG BitLen;										//ģ����ʵ��λ���ȱ�����8�ı���
		BYTE XCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8];	//�����ϵ��X����
		BYTE YCoordinate[ECC_MAX_YCOORDINATE_BITS_LEN/8];	//�����ϵ��Y����
	}ECCPUBLICKEYBLOB, *PECCPUBLICKEYBLOB;

	typedef struct Struct_ECCCIPHERBLOB{
		BYTE XCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8];	//��y�����Բ�����ϵĵ㣨x��y��
		BYTE YCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8];	//��x�����Բ�����ϵĵ㣨x��y��
		BYTE HASH[32];										//���ĵ��Ӵ�ֵ
		ULONG CipherLen;									//�������ݳ���
		BYTE Cipher[150];									//��������,ʵ�ʳ���ΪCipherLen
	} ECCCIPHERBLOB, *PECCCIPHERBLOB;

	typedef struct Struct_ECCSIGNATUREBLOB{
		BYTE r[ECC_MAX_XCOORDINATE_BITS_LEN/8];				//ǩ�������r����
		BYTE s[ECC_MAX_XCOORDINATE_BITS_LEN/8];				//ǩ�������s����
	} ECCSIGNATUREBLOB, *PECCSIGNATUREBLOB;

	typedef struct Struct_BLOCKCIPHERPARAM{
		BYTE IV[MAX_IV_LEN];	//��ʼ����			
		ULONG IVLen;			//��ʼ����ʵ�ʳ��ȣ����ֽڼ��㣩
		ULONG PaddingType;		//��䷽ʽ��0��ʾ����䣬1��ʾ����PKCS#5��ʽ�������
		ULONG FeedBitLen;		//����ֵ��λ���ȣ���λ���㣩ֻ���OFB��CFBģʽ
	} BLOCKCIPHERPARAM, *PBLOCKCIPHERPARAM;

	typedef struct SKF_ENVELOPEDKEYBLOB{
		ULONG Version; // ��ǰ�汾Ϊ 1
		ULONG ulSymmAlgID; // �Գ��㷨��ʶ���޶�ECBģʽ
		ULONG ulBits; // ������Կ�Ե���Կλ����
		BYTE cbEncryptedPriKey[64]; // ������Կ��˽Կ������
		ECCPUBLICKEYBLOB PubKey; // ������Կ�ԵĹ�Կ
		ECCCIPHERBLOB ECCCipherBlob; // �ñ�����Կ���ܵĶԳ���Կ���ġ�
	}ENVELOPEDKEYBLOB, *PENVELOPEDKEYBLOB;

	typedef struct Struct_FILEATTRIBUTE{
		CHAR FileName[32];	//�ļ���,�ԡ�\0��������ASCII�ַ�������󳤶�Ϊ32
		ULONG FileSize;		//�ļ���С
		ULONG ReadRights;	//��ȡȨ��
		ULONG WriteRights;	//д��Ȩ��
	} FILEATTRIBUTE, *PFILEATTRIBUTE;




ULONG DEVAPI SKF_SelectMF(DEVHANDLE hDev);

//������붨���˵��
#define SAR_OK                        0x00000000    //�ɹ�
#define SAR_FAIL                      0x0A000001	//ʧ��
#define SAR_UNKNOWNERR                0x0A000002	//�쳣����
#define SAR_NOTSUPPORTYETERR          0x0A000003	//��֧�ֵķ���
#define SAR_FILEERR                   0x0A000004	//�ļ���������
#define SAR_INVALIDHANDLEERR          0x0A000005	//��Ч�ľ��
#define SAR_INVALIDPARAMERR           0x0A000006	//��Ч�Ĳ���
#define SAR_READFILEERR               0x0A000007	//���ļ�����
#define SAR_WRITEFILEERR              0x0A000008	//д�ļ�����
#define SAR_NAMELENERR                0x0A000009	//���Ƴ��ȴ���
#define SAR_KEYUSAGEERR               0x0A00000A	//��Կ��;����
#define SAR_MODULUSLENERR             0x0A00000B	//ģ�ĳ��ȴ���
#define SAR_NOTINITIALIZEERR          0x0A00000C	//δ��ʼ��
#define SAR_OBJERR                    0x0A00000D	//�������
#define SAR_MEMORYERR                 0x0A00000E	//�ڴ����
#define SAR_TIMEOUTERR                0x0A00000F	//��ʱ
#define SAR_INDATALENERR              0x0A000010	//�������ݳ��ȴ���
#define SAR_INDATAERR                 0x0A000011	//�������ݴ���
#define SAR_GENRANDERR                0x0A000012	//�������������
#define SAR_HASHOBJERR                0x0A000013	//HASH�����
#define SAR_HASHERR                   0x0A000014	//HASH�������
#define SAR_GENRSAKEYERR              0x0A000015	//����RSA��Կ��
#define SAR_RSAMODULUSLENERR          0x0A000016	//RSA��Կģ������
#define SAR_CSPIMPRTPUBKEYERR         0x0A000017	//CSP�����빫Կ����
#define SAR_RSAENCERR                 0x0A000018	//RSA���ܴ���
#define SAR_RSADECERR                 0x0A000019	//RSA���ܴ���
#define SAR_HASHNOTEQUALERR           0x0A00001A	//HASHֵ�����
#define SAR_KEYNOTFOUNTERR            0x0A00001B	//��Կδ����
#define SAR_CERTNOTFOUNTERR           0x0A00001C	//֤��δ����
#define SAR_NOTEXPORTERR              0x0A00001D	//����δ����
#define SAR_DECRYPTPADERR             0x0A00001E	//����ʱ����������
#define SAR_MACLENERR                 0x0A00001F	//MAC���ȴ���
#define SAR_BUFFER_TOO_SMALL          0x0A000020	//����������
#define SAR_KEYINFOTYPEERR            0x0A000021	//��Կ���ʹ���
#define SAR_NOT_EVENTERR              0x0A000022	//���¼�����
#define SAR_DEVICE_REMOVED            0x0A000023	//�豸���Ƴ�
#define SAR_PIN_INCORRECT             0x0A000024	//PIN����ȷ
#define SAR_PIN_LOCKED                0x0A000025	//PIN������
#define SAR_PIN_INVALID               0x0A000026	//PIN��Ч
#define SAR_PIN_LEN_RANGE             0x0A000027	//PIN���ȴ���
#define SAR_USER_ALREADY_LOGGED_IN    0x0A000028	//�û��Ѿ���¼
#define SAR_USER_PIN_NOT_INITIALIZED  0x0A000029	//û�г�ʼ���û�����
#define SAR_USER_TYPE_INVALID         0x0A00002A	//PIN���ʹ���
#define SAR_APPLICATION_NAME_INVALID  0x0A00002B	//Ӧ��������Ч
#define SAR_APPLICATION_EXISTS        0x0A00002C	//Ӧ���Ѿ�����
#define SAR_USER_NOT_LOGGED_IN        0x0A00002D	//�û�û�е�¼
#define SAR_APPLICATION_NOT_EXISTS    0x0A00002E	//Ӧ�ò�����
#define SAR_FILE_ALREADY_EXIST        0x0A00002F	//�ļ��Ѿ�����
#define SAR_NO_ROOM                   0x0A000030	//�ռ䲻��
#define SAR_FILE_NOT_EXIST            0x0A000031	//�ļ�������
#define SAR_REACH_MAX_CONTAINER_COUNT 0x0A000032	//�Ѵﵽ���ɹ���������

//��ǩ ��ʶ�� ����
//���������㷨��ʶ
#define SGD_SM1_ECB		0x00000101	//SM1 �㷨ECB ����ģʽ
#define SGD_SM1_CBC		0x00000102	//SM1 �㷨CBC ����ģʽ
#define SGD_SM1_CFB		0x00000104	//SM1 �㷨CFB ����ģʽ
#define SGD_SM1_OFB		0x00000108	//SM1 �㷨OFB ����ģʽ
#define SGD_SM1_MAC		0x00000110	//SM1�㷨MAC����
#define SGD_SSF33_ECB	0x00000201	//SSF33�㷨ECB����ģʽ
#define SGD_SSF33_CBC	0x00000202	//SSF33�㷨CBC����ģʽ
#define SGD_SSF33_CFB	0x00000204	//SSF33�㷨CFB����ģʽ
#define SGD_SSF33_OFB	0x00000208	//SSF33�㷨OFB����ģʽ
#define SGD_SSF33_MAC	0x00000210	//SSF33�㷨MAC����
#define SGD_SMS4_ECB	0x00000401	//SMS4�㷨ECB����ģʽ
#define SGD_SMS4_CBC	0x00000402	//SMS4�㷨CBC����ģʽ
#define SGD_SMS4_CFB	0x00000404	//SMS4�㷨CFB����ģʽ
#define SGD_SMS4_OFB	0x00000408	//SMS4�㷨OFB����ģʽ
#define SGD_SMS4_MAC	0x00000410	//SMS4�㷨MAC����

#define SGD_TDES_ECB    0x00000801  //TDES �㷨ECB ����ģʽ

//�ǶԳ������㷨��ʶ
#define SGD_RSA			0x00010000		//RSA�㷨
#define SGD_SM2_1		0x00020100		//��Բ����ǩ���㷨
#define SGD_SM2_2		0x00020200		//��Բ������Կ����Э��
#define SGD_SM2_3		0x00020400		//��Բ���߼����㷨

//�����Ӵ��㷨��ʶ
#define SGD_SM3			0x00000001		//SM3�Ӵ��㷨
#define SGD_SHA1		0x00000002		//SHA1�Ӵ��㷨
#define SGD_SHA256		0x00000004		//SHA256�Ӵ��㷨


typedef ULONG (DEVAPI *SKF_EnumDev)(BOOL bPresent, LPSTR szNameList, ULONG *pulSize);//ö���豸�ӿ�����
typedef ULONG (DEVAPI *SKF_ConnectDev) (LPSTR szName, DEVHANDLE *phDev);
typedef ULONG (DEVAPI *SKF_DisConnectDev) (DEVHANDLE hDev);
typedef ULONG (DEVAPI *SKF_CreateApplication)(DEVHANDLE hDev, LPSTR szAppName, LPSTR szAdminPin, DWORD dwAdminPinRetryCount,LPSTR szUserPin, DWORD dwUserPinRetryCount,DWORD dwCreateFileRights, HAPPLICATION *phApplication);
typedef ULONG (DEVAPI *SKF_GetDevState)(LPSTR szDevName, ULONG *pulDevState);
typedef ULONG (DEVAPI *SKF_SetLabel) (DEVHANDLE hDev, LPSTR szLabel);
typedef ULONG (DEVAPI *SKF_GetDevInfo) (DEVHANDLE hDev, DEVINFO *pDevInfo);
typedef ULONG (DEVAPI *SKF_DevAuth) (DEVHANDLE hDev, BYTE *pbAuthData,ULONG ulLen);
typedef ULONG (DEVAPI *SKF_VerifyPIN) (HAPPLICATION hApplication, ULONG ulPINType, LPSTR szPIN, ULONG *pulRetryCount);
typedef ULONG (DEVAPI *SKF_EnumApplication)(DEVHANDLE hDev, LPSTR szAppName,ULONG *pulSize);
typedef ULONG (DEVAPI *SKF_OpenApplication)(DEVHANDLE hDev, LPSTR szAppName, HAPPLICATION *phApplication);
typedef ULONG (DEVAPI *SKF_CloseApplication)(HAPPLICATION hApplication);
typedef ULONG (DEVAPI *SKF_CreateContainer) (HAPPLICATION hApplication, LPSTR szContainerName, HCONTAINER *phContainer);
typedef ULONG (DEVAPI *SKF_DeleteContainer)(HAPPLICATION hApplication, LPSTR szContainerName);
typedef ULONG (DEVAPI *SKF_EnumContainer) (HAPPLICATION hApplication, LPSTR szContainerName, ULONG *pulSize);
typedef ULONG (DEVAPI *SKF_OpenContainer)(HAPPLICATION hApplication,LPSTR szContainerName,HCONTAINER *phContainer);
typedef ULONG (DEVAPI *SKF_CloseContainer)(HCONTAINER hContainer);
typedef ULONG (DEVAPI *SKF_DeleteApplication)(DEVHANDLE hDev, LPSTR szAppName);

typedef ULONG (DEVAPI *SKF_ImportCertificate)(HCONTAINER hContainer, BOOL bSignFlag,  BYTE* pbCert, ULONG ulCertLen);
typedef ULONG (DEVAPI *SKF_ExportCertificate)(HCONTAINER hContainer, BOOL bSignFlag,  BYTE* pbCert, ULONG *pulCertLen);
typedef ULONG (DEVAPI *SKF_GenRandom) (DEVHANDLE hDev, BYTE *pbRandom,ULONG ulRandomLen);
typedef ULONG (DEVAPI *SKF_GenECCKeyPair) (HCONTAINER hContainer, ULONG ulAlgId,ECCPUBLICKEYBLOB *pBlob);
typedef ULONG (DEVAPI *SKF_ECCSignData) (HCONTAINER hContainer, BYTE *pbData, ULONG  ulDataLen, PECCSIGNATUREBLOB pSignature);
typedef ULONG (DEVAPI *SKF_ExtECCVerify) (DEVHANDLE hDev, ECCPUBLICKEYBLOB*  pECCPubKeyBlob,BYTE* pbData, ULONG ulDataLen, PECCSIGNATUREBLOB pSignature);
typedef ULONG (DEVAPI *SKF_ExportPublicKey) (HCONTAINER hContainer, BOOL bSignFlag, BYTE* pbBlob, ULONG* pulBlobLen);

typedef ULONG (DEVAPI *SKF_DigestInit)(DEVHANDLE hDev, ULONG ulAlgID,  ECCPUBLICKEYBLOB *pPubKey, unsigned char *pucID, ULONG ulIDLen, HANDLE *phHash);
typedef ULONG (DEVAPI *SKF_Digest) (HANDLE hHash, BYTE *pbData, ULONG ulDataLen, BYTE *pbHashData, ULONG *pulHashLen);
typedef ULONG (DEVAPI *SKF_DigestUpdate) (HANDLE hHash, BYTE *pbData, ULONG  ulDataLen);
typedef ULONG (DEVAPI *SKF_DigestFinal) (HANDLE hHash, BYTE *pHashData, ULONG  *pulHashLen);
typedef ULONG (DEVAPI *SKF_ChangeDevAuthKey)(DEVHANDLE hDev, BYTE *pbKeyValue, ULONG ulKeyLen);

typedef ULONG (DEVAPI *SKF_SetSymmKey) (DEVHANDLE hDev, BYTE* pbKey, ULONG ulAlgID, HANDLE* phKey);
typedef ULONG (DEVAPI *SKF_EncryptInit) (HANDLE hKey, BLOCKCIPHERPARAM EncryptParam);
typedef ULONG (DEVAPI *SKF_Encrypt)(HANDLE hKey, BYTE * pbData, ULONG ulDataLen, BYTE *pbEncryptedData, ULONG *pulEncryptedLen);
typedef ULONG (DEVAPI *SKF_EncryptUpdate)(HANDLE hKey, BYTE * pbData, ULONG ulDataLen, BYTE *pbEncryptedData, ULONG *pulEncryptedLen);
typedef ULONG (DEVAPI *SKF_EncryptFinal)(HANDLE hKey, BYTE *pbEncryptedData, ULONG *ulEncryptedDataLen );
typedef ULONG (DEVAPI *SKF_GenRandom) (DEVHANDLE hDev, BYTE *pbRandom,ULONG ulRandomLen);

#ifdef __cplusplus
}       // Balance extern "C" above
#endif

#endif