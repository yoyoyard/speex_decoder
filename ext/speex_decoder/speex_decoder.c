#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <ruby.h>
#include <memory.h>
#include <stdio.h>

#if defined(__MACH__)
#include <stdlib.h>
#else
#include <malloc.h>
#endif

#include "TRSpeex.h"

int decode(char* in,char* out)
{

	FILE		  *fpInput;
	FILE		  *fpOutput;

	char aInputBuffer[MAX_FRAME_SIZE*10];
	char aOutputBuffer[MAX_FRAME_SIZE*10];

	int ret;
	int buffer_size;

	int nOutSize;
	int nPackNo;

	TRSpeexDecodeContex SpeexDecode;

	int nTotalLen;
	char buf[44];


	memset(aInputBuffer,0,sizeof(char)*MAX_FRAME_SIZE*10);


	memset(buf,0,44);


	buf[0] = 'R';
	buf[1] = 'I';
	buf[2] = 'F';
	buf[3] = 'F';

	buf[8] = 'W';
	buf[9] = 'A';
	buf[10] = 'V';
	buf[11] = 'E';
	buf[12] = 'f';
	buf[13] = 'm';
	buf[14] = 't';
	buf[15] = 0x20;

	buf[16] = 0x10;
	buf[20] = 0x01;
	buf[22] = 0x01;
	buf[24] = 0x80;
	buf[25] = 0x3E;
	buf[29]= 0x7D;
	buf[32] = 0x02;
	buf[34] = 0x10;
	buf[36] = 'd';
	buf[37] = 'a';
	buf[38] = 't';
	buf[39] = 'a';




	TRSpeexDecodeInit(&SpeexDecode);

	fpInput = fopen(in,"rb");


	if(fpInput == NULL)
	{
		printf("can't open input spx file");
		return 1;
	}

	fpOutput = fopen(out,"wb");

	if(fpOutput == NULL)
	{
		printf("can't open output file");
		return 2;
	}

	fwrite(buf,1,44,fpOutput);


	nTotalLen = 0;


	buffer_size = 6;

	ret = fread(aInputBuffer, 1,buffer_size,fpInput);

	while(1)
	{
		TRSpeexDecode(&SpeexDecode,aInputBuffer,buffer_size,aOutputBuffer, &nOutSize);

		ret = fread(aInputBuffer, 1,buffer_size, fpInput);
		if(ret != buffer_size)
			break;

		fwrite(aOutputBuffer,1, nOutSize,fpOutput);
		nTotalLen += nOutSize;

	}

	TRSpeexDecodeRelease(&SpeexDecode);

	fseek(fpOutput,40,SEEK_SET);
	fwrite(&nTotalLen,1,4,fpOutput);

	fseek(fpOutput,4,SEEK_SET);
	nTotalLen += 36;
	fwrite(&nTotalLen,1,4,fpOutput);
	fclose(fpOutput);
	fclose(fpInput);





	return 0;
}

VALUE SpeexDecoder = Qnil;

void Init_speex_decoder();

VALUE rb_decode(VALUE self, VALUE input, VALUE output);

void Init_speex_decoder() {
  SpeexDecoder = rb_define_module("SpeexDecoder");
  rb_define_singleton_method(SpeexDecoder, "decode", rb_decode, 2);
}

VALUE rb_decode(VALUE self, VALUE input, VALUE output) {
	int c_result;

	c_result = decode(RSTRING(input), RSTRING(output));

	VALUE result = UINT2NUM(c_result);
	return result;
}
