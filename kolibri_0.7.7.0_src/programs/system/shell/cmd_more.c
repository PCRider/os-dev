
int cmd_more(char file[])
{

kol_struct70	k70;
kol_struct_BDVK	bdvk;
unsigned	result, filesize, pos, i;
char		buf[81]; //�����
char		temp[256];
unsigned	flags;

if (NULL == file)
	{
	printf ("  less filename\n\r");
	return FALSE;
		}

if ( '/' == file[0])
	{
	strcpy(temp, file);

	if ( !file_check(temp) )
		{
		return FALSE;
		}
	}
else
	{
	strcpy(temp, cur_dir);
	strcat(temp, file);
	
	if ( !file_check(temp) )
		{
		return FALSE;
		}
	}

k70.p00 = 5;
k70.p04 = k70.p08 = k70.p12 = 0;
k70.p16 = &bdvk;
k70.p20 = 0;
k70.p21 = temp;

result = kol_file_70(&k70); // �������� ���������� � �����
if ( 0 != result ) 
	return FALSE;

filesize = bdvk.p32[0]; // �������� ������ �����

buf[80]=0;
flags = con_get_flags();

for (pos=0;pos<filesize;pos+=80)
	{

	memset(buf, 0, 80);

	k70.p00 = 0;
	k70.p04 = pos;
	k70.p08 = 0;
	k70.p12 = 80;
	k70.p16 = buf;
	k70.p20 = 0;
	k70.p21 = temp;

	result = kol_file_70(&k70); // ������ 80 ��������
	for (i=0; i<80; i++)
		{

		if (27 == buf[i])
			con_set_flags(flags|0x100);
		else con_set_flags(flags);

		printf ("%c", buf[i]);
		}
	if ( 0 != result ) 
		{
		con_set_flags(flags);
		printf ("\n\r");
		return TRUE;	
		}

	}
con_set_flags(flags);
printf ("\n\r");
return TRUE;
}
