#include <fstream>

//macro to load LUT
#define INIT_HR {if (!initHR()){  printf("Problem Opening HRLUTfinal.dat\n");return 0;}}
#define ULL long long	

	//lookup tables
	short flushes[8192],
	      EL0[13],
	      EL1[13][13],
	      EL2[91][13],
	      EL3[455][13],
	      EL4[1820][13],
	      EL5[6188][13],
	      EL6[18564][13];
	
	ULL hand, //given hand
		  x=1;   //64bit 1

//initializing LUT from file "H" 
int initHR (){
	FILE * f1 = fopen("H","rb");
	
	if (!f1) {									  
		printf("Problem Opening HRLUTfinal.dat\n");
		return 0;
	}
	
	size_t   read_lut = fread(EL0, sizeof(EL0), 1, f1);
           read_lut = fread(EL1, sizeof(EL1), 1, f1);
			     read_lut = fread(EL2, sizeof(EL2), 1, f1);
			     read_lut = fread(EL3, sizeof(EL3), 1, f1);
			     read_lut = fread(EL4, sizeof(EL4), 1, f1);
			     read_lut = fread(EL5, sizeof(EL5), 1, f1);
			     read_lut = fread(EL6, sizeof(EL6), 1, f1);
			     read_lut=fread(flushes,sizeof(flushes),1,f1);
	
	fclose(f1);
	return 1;
}

  
	inline short HRoffsuit (short c1, short c2, short c3, short c4, short c5, short c6, short c7){ 
		return EL6[EL5[EL4[EL3[EL2[EL1[EL0[c1%13]][c2%13]][c3%13]][c4%13]][c5%13]][c6%13]][c7%13]; 
	}
	
	inline short Eval (short c1, short c2, short c3, short c4, short c5, int c6, short c7){
		hand=(x<<c1)|(x<<c2)|(x<<c3)|(x<<c4)|(x<<c5)|(x<<c6)|(x<<c7); //add cards to 52-bit mask
		short m,n;
		m= flushes[hand&0x1fff]|flushes[(hand>>13)&0x1fff]|        //split 52-bit mask into 13-bit pieces for each suit
				flushes[(hand>>26)&0x1fff]|flushes[(hand>>39)&0x1fff];//and use each piece as index to flushes array
		n=	HRoffsuit(c1,c2,c3,c4,c5,c6,c7);                     //comb trough tables having ranks only disregarding suits
		if (!m) m=n;                                            //if no flush detected then return our second value 
		return m;
	}
	
/*		Use snippet

Eval(c1,c2,c3,c4,c5,c6,c7);
	
*/
