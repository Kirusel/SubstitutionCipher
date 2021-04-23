#include "SubstitutionModule.h"

SubstitutionModule::SubstitutionModule(int k)
{
    this->key=k;
}

wstring SubstitutionModule::Encode(SubstitutionModule key, wstring& data)
{
	int h;
	if (data.length()%key.key!=0) 
		h=data.length()/key.key+1; 
	else
		h=data.length()/key.key;
		
	char a[h][key.key];
	auto k=0;
	
	for (int i=0;i<h;i++) {
		for (int j=0;j<key.key;j++) {
			if (k<data.length()) {
				a[i][j]=data[k];
				k++;
			}
			else a[i][j]=' ';
			}
		}	
	wstring encode;
	for (int i=0;i<key.key;i++)	{
		for (int j=0;j<h;j++)	{
		encode+=a[j][i];
		}
	}
	return encode;
}


wstring SubstitutionModule::Decode(SubstitutionModule key, wstring& data)
{
	int h = data.length()/key.key;;
	char a[key.key][h];
	auto k = 0;
	
	for (int i=0;i<key.key;i++)	{
		for (int j=0;j<h;j++)	{
			if (k < data.length()) {
				a[i][j]=data[k];
				k++;
			} else {
				a[i][j]=' ';
				k++;
			} 
		}
	}	
	
	wstring decode;
	for (int i=0;i<h;i++)	{
		for (int j=0;j<key.key;j++)	{
			decode+=a[j][i];
		}
	}
	
	return decode;
}