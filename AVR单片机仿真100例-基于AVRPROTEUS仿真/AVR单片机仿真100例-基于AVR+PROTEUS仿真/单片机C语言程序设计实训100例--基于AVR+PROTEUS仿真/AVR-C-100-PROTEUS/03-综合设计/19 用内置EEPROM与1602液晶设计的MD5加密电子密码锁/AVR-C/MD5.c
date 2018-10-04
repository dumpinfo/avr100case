//-----------------------------------------------------------------
// ����: MD5���ܳ���
//-----------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#define INT8U   unsigned char
#define INT16U  unsigned int
#define INT32U  unsigned long
#define PINT8U  unsigned char *

//MD5�任������
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

typedef struct      //MD5���ܴ��������Ľṹ
{
  INT32U count[2];  //��Ϣλ��(bits length)
  INT32U state[4];  //MD5���ܳ�ʼ������MD5ժҪ��������(128λ,16�ֽ�,32��16�����ַ�)
  INT8U buffer[64]; //������(512λ)
} MD5_CTX;

static INT8U PADDING[64] = //512�����λ,��1λΪ1,����λΪ0
{
  0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

//MD5���ܵĻ���λ��������F,G,H,I,����x,y,zȫ��Ϊ32bits�ĳ���������
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

//��xѭ������nλ
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

//FF, GG, HH, ��II�ֱ����ڵ�1,2,3,4��ת��
#define FF(a, b, c, d, x, s, ac) \
{(a)+=F((b),(c),(d)) + (x) + (INT32U)(ac);(a)=ROTATE_LEFT((a),(s));(a)+=(b);}
#define GG(a, b, c, d, x, s, ac) \
{(a)+=G((b),(c),(d)) + (x) + (INT32U)(ac);(a)=ROTATE_LEFT((a),(s));(a)+=(b);}
#define HH(a, b, c, d, x, s, ac) \
{(a)+=H((b),(c),(d)) + (x) + (INT32U)(ac);(a)=ROTATE_LEFT((a),(s));(a)+=(b);}
#define II(a, b, c, d, x, s, ac) \
{(a)+=I((b),(c),(d)) + (x) + (INT32U)(ac);(a)=ROTATE_LEFT((a),(s));(a)+=(b);}

//MD5��غ�������
void MD5Init  (MD5_CTX *context);
void MD5Update(MD5_CTX *context, INT8U *input,INT16U inputLen);  
void MD5Final (INT8U digest[16], MD5_CTX *context);
static void MD5Transform(INT32U [4], INT8U [64]) ;
static void Encode(INT8U  *, INT32U *, INT16U);
static void Decode(INT32U *, INT8U  *, INT16U);
//-----------------------------------------------------------------
// MD5��ʼ��
//-----------------------------------------------------------------
void MD5Init(MD5_CTX *context)
{
    //��ʼλ��(bits length)Ϊ0
	context->count[0] = 0;
	context->count[1] = 0;
	//�ĸ����ڼ���ժҪ�ĳ����ͻ���Ϊ:
	//A: 01 23 45 67 
	//B: 89 AB CD EF 
	//C: FE DC DA 98 
	//D: 76 54 32 10 
	//��Little Endian��ʽ�����state
	context->state[0] = 0x67452301;
	context->state[1] = 0xEFCDAB89;
	context->state[2] = 0x98BADCFE;
	context->state[3] = 0x10325476;
}

//-----------------------------------------------------------------
// MD5���ļ�����¹���
//-----------------------------------------------------------------
void MD5Update(MD5_CTX *context, INT8U *input,INT16U inputLen)
{



}

//-----------------------------------------------------------------
// MD5�������任����,�������ܽ��д��ժҪ����digest
//-----------------------------------------------------------------
void MD5Final(INT8U digest[16], MD5_CTX *context)
{

















}

//-----------------------------------------------------------------
// MD5����ת������
//-----------------------------------------------------------------
static void MD5Transform(INT32U state[4], INT8U block[64])
{ 
	//�任֮ǰa,b,c,d���ȷֱ��ȡ�ϴα任���state[0]~state[3]��ֵ
	INT32U a = state[0], b = state[1], c = state[2], d = state[3], x[16];
	//��512λ��block����Ϊ������(INT32U)����x(16��Ԫ��)
	Decode (x, block, 64);
	//��һ�ֱ任---------------------------------------------------
	FF (a, b, c, d, x[ 0], S11, 0xd76aa478); //1 
	FF (d, a, b, c, x[ 1], S12, 0xe8c7b756); //2 
	FF (c, d, a, b, x[ 2], S13, 0x242070db); //3 
	FF (b, c, d, a, x[ 3], S14, 0xc1bdceee); //4 
	FF (a, b, c, d, x[ 4], S11, 0xf57c0faf); //5 
	FF (d, a, b, c, x[ 5], S12, 0x4787c62a); //6 
	FF (c, d, a, b, x[ 6], S13, 0xa8304613); //7 
	FF (b, c, d, a, x[ 7], S14, 0xfd469501); //8 
	FF (a, b, c, d, x[ 8], S11, 0x698098d8); //9 
	FF (d, a, b, c, x[ 9], S12, 0x8b44f7af); //10 
	FF (c, d, a, b, x[10], S13, 0xffff5bb1); //11 
	FF (b, c, d, a, x[11], S14, 0x895cd7be); //12 
	FF (a, b, c, d, x[12], S11, 0x6b901122); //13 
	FF (d, a, b, c, x[13], S12, 0xfd987193); //14 
	FF (c, d, a, b, x[14], S13, 0xa679438e); //15 
	FF (b, c, d, a, x[15], S14, 0x49b40821); //16 
	//�ڶ��ֱ任---------------------------------------------------
	GG (a, b, c, d, x[ 1], S21, 0xf61e2562); //17 
	GG (d, a, b, c, x[ 6], S22, 0xc040b340); //18 
	GG (c, d, a, b, x[11], S23, 0x265e5a51); //19 
	GG (b, c, d, a, x[ 0], S24, 0xe9b6c7aa); //20 
	GG (a, b, c, d, x[ 5], S21, 0xd62f105d); //21 
	GG (d, a, b, c, x[10], S22, 0x02441453); //22 
	GG (c, d, a, b, x[15], S23, 0xd8a1e681); //23 
	GG (b, c, d, a, x[ 4], S24, 0xe7d3fbc8); //24 
	GG (a, b, c, d, x[ 9], S21, 0x21e1cde6); //25 
	GG (d, a, b, c, x[14], S22, 0xc33707d6); //26 
	GG (c, d, a, b, x[ 3], S23, 0xf4d50d87); //27 
	GG (b, c, d, a, x[ 8], S24, 0x455a14ed); //28 
	GG (a, b, c, d, x[13], S21, 0xa9e3e905); //29 
	GG (d, a, b, c, x[ 2], S22, 0xfcefa3f8); //30 
	GG (c, d, a, b, x[ 7], S23, 0x676f02d9); //31 
	GG (b, c, d, a, x[12], S24, 0x8d2a4c8a); //32 
	//�����ֱ任---------------------------------------------------
	HH (a, b, c, d, x[ 5], S31, 0xfffa3942); //33 
	HH (d, a, b, c, x[ 8], S32, 0x8771f681); //34 
	HH (c, d, a, b, x[11], S33, 0x6d9d6122); //35 
	HH (b, c, d, a, x[14], S34, 0xfde5380c); //36 
	HH (a, b, c, d, x[ 1], S31, 0xa4beea44); //37 
	HH (d, a, b, c, x[ 4], S32, 0x4bdecfa9); //38 
	HH (c, d, a, b, x[ 7], S33, 0xf6bb4b60); //39 
	HH (b, c, d, a, x[10], S34, 0xbebfbc70); //40 
	HH (a, b, c, d, x[13], S31, 0x289b7ec6); //41 
	HH (d, a, b, c, x[ 0], S32, 0xeaa127fa); //42 
	HH (c, d, a, b, x[ 3], S33, 0xd4ef3085); //43 
	HH (b, c, d, a, x[ 6], S34, 0x04881d05); //44 
	HH (a, b, c, d, x[ 9], S31, 0xd9d4d039); //45 
	HH (d, a, b, c, x[12], S32, 0xe6db99e5); //46 
	HH (c, d, a, b, x[15], S33, 0x1fa27cf8); //47 
	HH (b, c, d, a, x[ 2], S34, 0xc4ac5665); //48 
	//�����ֱ任---------------------------------------------------
	II (a, b, c, d, x[ 0], S41, 0xf4292244); //49 
	II (d, a, b, c, x[ 7], S42, 0x432aff97); //50 
	II (c, d, a, b, x[14], S43, 0xab9423a7); //51 
	II (b, c, d, a, x[ 5], S44, 0xfc93a039); //52 
	II (a, b, c, d, x[12], S41, 0x655b59c3); //53 
	II (d, a, b, c, x[ 3], S42, 0x8f0ccc92); //54 
	II (c, d, a, b, x[10], S43, 0xffeff47d); //55 
	II (b, c, d, a, x[ 1], S44, 0x85845dd1); //56 
	II (a, b, c, d, x[ 8], S41, 0x6fa87e4f); //57 
	II (d, a, b, c, x[15], S42, 0xfe2ce6e0); //58 
	II (c, d, a, b, x[ 6], S43, 0xa3014314); //59 
	II (b, c, d, a, x[13], S44, 0x4e0811a1); //60 
	II (a, b, c, d, x[ 4], S41, 0xf7537e82); //61 
	II (d, a, b, c, x[11], S42, 0xbd3af235); //62 
	II (c, d, a, b, x[ 2], S43, 0x2ad7d2bb); //63 
	II (b, c, d, a, x[ 9], S44, 0xeb86d391); //64 

	//���任���a,c,b,d�ֱ��ۼӵ�state[0]~state[3]
	state[0] += a; state[1] += b; state[2] += c; state[3] += d;
	//������x��0
	memset ((PINT8U)x, 0, sizeof (x));
}

//-----------------------------------------------------------------
// ��32λ�ĳ���������inputת��Ϊ8λ���ֽ�����output,(INT32U)-->(INT8U)
//-----------------------------------------------------------------
static void Encode(INT8U *output,INT32U *input,INT16U len)
{



}

//-----------------------------------------------------------------
// ��8λ���ֽ�����intputת��Ϊ32λ�ĳ���������output,(INT8U)-->(INT32U)
//-----------------------------------------------------------------
static void Decode(INT32U *output,INT8U *input,INT16U len)
{



}

//-----------------------------------------------------------------
// ��ԭʼ�ַ���str����MD5���ܲ����������ַ���
//-----------------------------------------------------------------
char* MD5String(char *str) 
{



}
