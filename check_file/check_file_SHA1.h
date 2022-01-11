#ifndef HLS_CHECK_FILE_SHA1_H
#define HLS_CHECK_FILE_SHA1_H

#include "../common/string.h"
#include "../common/fstream.h"

class SHA1
{
	public:
		SHA1();
		SHA1(unsigned char *input, size_t length);
		SHA1(const string &str);
		SHA1(ifstream &in);
		void update(unsigned char *input, size_t length);
		void update(const string &str);
		void update(ifstream &in);
		string result();
		void reset();
		
	private:
		unsigned int h0,h1,h2,h3,h4;
		unsigned int nblocks;
		unsigned char buf[64];
		int count;
		void transform(unsigned char *data);
		void final();
		
		static const size_t BUFFER_SIZE=1024;
};

/****************
* Rotate a 32 bit integer by n bytes
*/
#if defined(__GNUC__) && defined(__i386__)
static inline unsigned int rol(unsigned int x,int n){__asm__("roll %%cl,%0":"=r"(x):"0"(x),"c"(n));return x;}
#else
#define rol(x,n) (((x)<<(n))|((x)>>(32-(n))))
#endif

#define K1 0x5A827999L
#define K2 0x6ED9EBA1L
#define K3 0x8F1BBCDCL
#define K4 0xCA62C1D6L
#define F1(x,y,z) (z^(x&(y^z)))
#define F2(x,y,z) (x^y^z)
#define F3(x,y,z) ((x&y)|(z&(x|y)))
#define F4(x,y,z) (x^y^z)
#define M(i) (tm=x[i&0x0f]^x[(i-14)&0x0f]^x[(i-8)&0x0f]^x[(i-3)&0x0f],(x[i&0x0f]=rol(tm,1)))
#define R(a,b,c,d,e,f,k,m) do{\
	e+=rol(a,5)+f(b,c,d)+k+m;\
	b=rol(b,30);\
}while(0)
#ifdef BIG_ENDIAN_HOST
#define X(a) do{*(unsigned int*)p=h##a;p+=4;}while(0)
#else/* little endian */
#define X(a) do{*p++=h##a>>24;*p++=h##a>>16;*p++=h##a>>8;*p++=h##a;}while(0)
#endif

SHA1::SHA1()
{
	reset();
	return;
}

SHA1::SHA1(unsigned char *input, size_t length)
{
	reset();
	update(input,length);
	return;
}

SHA1::SHA1(const string &str)
{
	reset();
	update(str);
	return;
}

SHA1::SHA1(ifstream &in)
{
	reset();
	update(in);
	return;
}

void SHA1::reset()
{
	h0=0x67452301;
	h1=0xefcdab89;
	h2=0x98badcfe;
	h3=0x10325476;
	h4=0xc3d2e1f0;
	nblocks=0;
	count=0;
	return;
}

/****************
* Transform the message X which consists of 16 32-bit-words
*/
void SHA1::transform(unsigned char *data)
{
	unsigned int a,b,c,d,e,tm;
	unsigned int x[16];
	/* get values from the chaining vars */
	a=h0;
    b=h1;
    c=h2;
    d=h3;
    e=h4;
#ifdef BIG_ENDIAN_HOST
	memcpy(x,data,64);
#else
	{
		int i;
		unsigned char *p2;
		for(i=0,p2=(unsigned char*)x;i<16;i++,p2+=4)
		{
			p2[3]=*data++;
			p2[2]=*data++;
			p2[1]=*data++;
			p2[0]=*data++;
		}
	}
#endif
	R(a,b,c,d,e,F1,K1,x[0]);
	R(e,a,b,c,d,F1,K1,x[1]);
	R(d,e,a,b,c,F1,K1,x[2]);
	R(c,d,e,a,b,F1,K1,x[3]);
	R(b,c,d,e,a,F1,K1,x[4]);
	R(a,b,c,d,e,F1,K1,x[5]);
	R(e,a,b,c,d,F1,K1,x[6]);
	R(d,e,a,b,c,F1,K1,x[7]);
	R(c,d,e,a,b,F1,K1,x[8]);
	R(b,c,d,e,a,F1,K1,x[9]);
	R(a,b,c,d,e,F1,K1,x[10]);
	R(e,a,b,c,d,F1,K1,x[11]);
	R(d,e,a,b,c,F1,K1,x[12]);
	R(c,d,e,a,b,F1,K1,x[13]);
	R(b,c,d,e,a,F1,K1,x[14]);
	R(a,b,c,d,e,F1,K1,x[15]);
	R(e,a,b,c,d,F1,K1,M(16));
	R(d,e,a,b,c,F1,K1,M(17));
	R(c,d,e,a,b,F1,K1,M(18));
	R(b,c,d,e,a,F1,K1,M(19));
	R(a,b,c,d,e,F2,K2,M(20));
	R(e,a,b,c,d,F2,K2,M(21));
	R(d,e,a,b,c,F2,K2,M(22));
	R(c,d,e,a,b,F2,K2,M(23));
	R(b,c,d,e,a,F2,K2,M(24));
	R(a,b,c,d,e,F2,K2,M(25));
	R(e,a,b,c,d,F2,K2,M(26));
	R(d,e,a,b,c,F2,K2,M(27));
	R(c,d,e,a,b,F2,K2,M(28));
	R(b,c,d,e,a,F2,K2,M(29));
	R(a,b,c,d,e,F2,K2,M(30));
	R(e,a,b,c,d,F2,K2,M(31));
	R(d,e,a,b,c,F2,K2,M(32));
	R(c,d,e,a,b,F2,K2,M(33));
	R(b,c,d,e,a,F2,K2,M(34));
	R(a,b,c,d,e,F2,K2,M(35));
	R(e,a,b,c,d,F2,K2,M(36));
	R(d,e,a,b,c,F2,K2,M(37));
	R(c,d,e,a,b,F2,K2,M(38));
	R(b,c,d,e,a,F2,K2,M(39));
	R(a,b,c,d,e,F3,K3,M(40));
	R(e,a,b,c,d,F3,K3,M(41));
	R(d,e,a,b,c,F3,K3,M(42));
	R(c,d,e,a,b,F3,K3,M(43));
	R(b,c,d,e,a,F3,K3,M(44));
	R(a,b,c,d,e,F3,K3,M(45));
	R(e,a,b,c,d,F3,K3,M(46));
	R(d,e,a,b,c,F3,K3,M(47));
	R(c,d,e,a,b,F3,K3,M(48));
	R(b,c,d,e,a,F3,K3,M(49));
	R(a,b,c,d,e,F3,K3,M(50));
	R(e,a,b,c,d,F3,K3,M(51));
	R(d,e,a,b,c,F3,K3,M(52));
	R(c,d,e,a,b,F3,K3,M(53));
	R(b,c,d,e,a,F3,K3,M(54));
	R(a,b,c,d,e,F3,K3,M(55));
	R(e,a,b,c,d,F3,K3,M(56));
	R(d,e,a,b,c,F3,K3,M(57));
	R(c,d,e,a,b,F3,K3,M(58));
	R(b,c,d,e,a,F3,K3,M(59));
	R(a,b,c,d,e,F4,K4,M(60));
	R(e,a,b,c,d,F4,K4,M(61));
	R(d,e,a,b,c,F4,K4,M(62));
	R(c,d,e,a,b,F4,K4,M(63));
	R(b,c,d,e,a,F4,K4,M(64));
	R(a,b,c,d,e,F4,K4,M(65));
	R(e,a,b,c,d,F4,K4,M(66));
	R(d,e,a,b,c,F4,K4,M(67));
	R(c,d,e,a,b,F4,K4,M(68));
	R(b,c,d,e,a,F4,K4,M(69));
	R(a,b,c,d,e,F4,K4,M(70));
	R(e,a,b,c,d,F4,K4,M(71));
	R(d,e,a,b,c,F4,K4,M(72));
	R(c,d,e,a,b,F4,K4,M(73));
	R(b,c,d,e,a,F4,K4,M(74));
	R(a,b,c,d,e,F4,K4,M(75));
	R(e,a,b,c,d,F4,K4,M(76));
	R(d,e,a,b,c,F4,K4,M(77));
	R(c,d,e,a,b,F4,K4,M(78));
	R(b,c,d,e,a,F4,K4,M(79));
	/* Update chaining vars */
	h0+=a;
	h1+=b;
	h2+=c;
	h3+=d;
	h4+=e;
	return;
}

/* Update the message digest with the contents
* of INBUF with length INLEN.
*/
void SHA1::update(unsigned char *inbuf,size_t inlen)
{
	if(count==64)/* flush the buffer */
	{
		transform(buf);
		count=0;
		nblocks++;
	}
	if(!inbuf)
		return;
	if(count)
	{
		for(;inlen && count<64;inlen--)
			buf[count++]=*inbuf++;
		update(NULL,0);
		if(!inlen)
			return;
	}
	while(inlen>=64)
	{
		transform(inbuf);
		count=0;
		nblocks++;
		inlen-=64;
		inbuf+=64;
	}
	for(;inlen && count<64;inlen--)
		buf[count++]=*inbuf++;
	return;
}

void SHA1::update(const string &str)
{
	update((unsigned char *)str.c_str(), str.length());
	return;
}

void SHA1::update(ifstream &in)
{
	if(!in)
		return;
	std::streamsize length;
	char buffer[BUFFER_SIZE];
	while(!in.eof())
	{
		in.read(buffer,BUFFER_SIZE);
		length=in.gcount();
		if(length>0)
			update((unsigned char *)buffer,length);
	}
	in.close();
	return;
}

/* The routine final terminates the computation and
* returns the digest.
* The handle is prepared for a new cycle, but adding bytes to the
* handle will the destroy the returned buffer.
* Returns: 20 bytes representing the digest.
*/
void SHA1::final()
{
	unsigned int t,msb,lsb;
	unsigned char *p;
	update(NULL,0);/* flush */
	t=nblocks;
	/* multiply by 64 to make a byte count */
	lsb=t<<6;
	msb=t>>26;
	/* add the count */
	t=lsb;
	if((lsb+=count)<t)
		msb++;
	/* multiply by 8 to make a bit count */
	t=lsb;
	lsb<<=3;
	msb<<=3;
	msb|=t>>29;
	if(count<56)/* enough room */
	{
		buf[count++]=0x80;/* pad */
		while(count<56)
			buf[count++]=0;/* pad */
	}
	else/* need one extra block */
	{
		buf[count++]=0x80;/* pad character */
		while(count<64)
			buf[count++]=0;
		update(NULL,0);/* flush */
		memset(buf,0,56);/* fill next block with zeroes */
	}
	/* append the 64 bit count */
	buf[56]=msb>>24;
	buf[57]=msb>>16;
	buf[58]=msb>>8;
	buf[59]=msb;
	buf[60]=lsb>>24;
	buf[61]=lsb>>16;
	buf[62]=lsb>>8;
	buf[63]=lsb;
	transform(buf);
	p=buf;
	X(0);
	X(1);
	X(2);
	X(3);
	X(4);
}

string SHA1::result()
{
	final();
	string _sha1;
	for(int i=0;i<20;i++)
	{
		char *temp=(char*)calloc(3,sizeof(char*));
		sprintf(temp,"%02x",buf[i]);
		_sha1+=temp[0];
		_sha1+=temp[1];
	}
	return _sha1;
}

#undef K1
#undef K2
#undef K3
#undef K4
#undef F1
#undef F2
#undef F3
#undef F4
#undef M
#undef R
#undef X

#endif
//https://blog.csdn.net/testcs_dn/article/details/25569975
