
sz htext,'TINYPAD ',APP_VERSION

menubar_res main_menu,\
  ru,'����'	,mm.File    ,onshow.file   ,\
  ru,'�ࠢ��'	,mm.Edit    ,onshow.edit   ,\
  ru,'����'	,mm.Search  ,onshow.search ,\
  ru,'�����'	,mm.Run     ,onshow.run    ,\
  ru,'����஢��',mm.Encoding,onshow.recode ,\
  ru,'��樨'	,mm.Options ,onshow.options,\
\
  en,'File'    ,mm.File    ,onshow.file   ,\
  en,'Edit'    ,mm.Edit    ,onshow.edit   ,\
  en,'Search'  ,mm.Search  ,onshow.search ,\
  en,'Run'     ,mm.Run	   ,onshow.run	  ,\
  en,'Encoding',mm.Encoding,onshow.recode ,\
  en,'Options' ,mm.Options ,onshow.options,\
\
  et,'Fail'	,mm.File    ,onshow.file   ,\
  et,'Muuda'	,mm.Edit    ,onshow.edit   ,\
  et,'Otsi'	,mm.Search  ,onshow.search ,\
  et,'K�ivita'	,mm.Run     ,onshow.run    ,\
  et,'Kodeering',mm.Encoding,onshow.recode ,\
  et,'Seaded'	,mm.Options ,onshow.options

popup_res mm.File,\
  ru,'����'	       ,'Ctrl+N'      ,New   ,\
  ru,'������...'      ,'Ctrl+O'      ,Open  ,\
  ru,'���࠭���'       ,'Ctrl+S'      ,Save  ,\
  ru,'���࠭��� ���...','Ctrl+Shift+S',SaveAs,\
  ru,'-'	       ,''	      ,      ,\
  ru,'�������'	       ,'Ctrl+F4'     ,Close ,\
  ru,'-'	       ,''	      ,      ,\
  ru,'��室'	       ,'Alt+X'       ,Exit  ,\
\
  en,'New'	 ,'Ctrl+N'	,New   ,\
  en,'Open...'	 ,'Ctrl+O'	,Open  ,\
  en,'Save'	 ,'Ctrl+S'	,Save  ,\
  en,'Save as...','Ctrl+Shift+S',SaveAs,\
  en,'-'	 ,''		,      ,\
  en,'Close'	 ,'Ctrl+F4'	,Close ,\
  en,'-'	 ,''		,      ,\
  en,'Exit'	 ,'Alt+X'	,Exit,\
\
  et,'Uus'		 ,'Ctrl+N'	,New   ,\
  et,'Ava...'		 ,'Ctrl+O'	,Open  ,\
  et,'Salvesta' 	 ,'Ctrl+S'	,Save  ,\
  et,'Salvesta nimega...','Ctrl+Shift+S',SaveAs,\
  et,'-'		 ,''		,      ,\
  et,'Sulge'		 ,'Ctrl+F4'	,Close ,\
  et,'-'		 ,''		,      ,\
  et,'V�lju'		 ,'Alt+X'	,Exit

popup_res mm.Edit,\
  ru,'��१���'    ,'Ctrl+X',Cut   ,\
  ru,'����஢���'  ,'Ctrl+C',Copy  ,\
  ru,'��⠢���'    ,'Ctrl+V',Insert,\
  ru,'�������'	   ,''	    ,Delete,\
  ru,'-'	   ,''	    ,	   ,\
  ru,'�뤥���� ���','Ctrl+A',SelAll,\
\
  en,'Cut'	 ,'Ctrl+X',Cut	 ,\
  en,'Copy'	 ,'Ctrl+C',Copy  ,\
  en,'Paste'	 ,'Ctrl+V',Insert,\
  en,'Delete'	 ,''	  ,Delete,\
  en,'-'	 ,''	  ,	 ,\
  en,'Select all','Ctrl+A',SelAll,\
\
  et,'L�ika'	 ,'Ctrl+X',Cut	 ,\
  et,'Kopeeri'	 ,'Ctrl+C',Copy  ,\
  et,'Kleebi'	 ,'Ctrl+V',Insert,\
  et,'Kustuta'	 ,''	  ,Delete,\
  et,'-'	 ,''	  ,	 ,\
  et,'Vali k�ik' ,'Ctrl+A',SelAll

popup_res mm.Search,\
  ru,'��३�...' ,'Ctrl+G',Position,\
  ru,'-'	  ,''	   ,	    ,\
  ru,'����...'   ,'Ctrl+F',Find    ,\
  ru,'���� �����','F3'    ,FindNext,\
  ru,'��������...','Ctrl+H',Replace ,\
\
  en,'Position...','Ctrl+G',Position,\
  en,'-'	  ,''	   ,	    ,\
  en,'Find...'	  ,'Ctrl+F',Find    ,\
  en,'Find next'  ,'F3'    ,FindNext,\
  en,'Replace...' ,'Ctrl+H',Replace ,\
\
  et,'Positsioon...','Ctrl+G',Position,\
  et,'-'	    ,''      ,	      ,\
  et,'Leia...'	    ,'Ctrl+F',Find    ,\
  et,'Leia j�rgmine','F3'    ,FindNext,\
  et,'Asenda...'    ,'Ctrl+H',Replace

popup_res mm.Run,\
  ru,'��������'	,'F9'	  ,Run	   ,\
  ru,'�������஢���'	,'Ctrl+F9',Compile ,\
  ru,'-'		,''	  ,	   ,\
  ru,'��᪠ �⫠���'	,''	  ,DbgBoard,\
  ru,'���⥬�� �㭪樨',''	  ,SysFuncs,\
\
  en,'Run'		,'F9'	  ,Run	   ,\
  en,'Compile'		,'Ctrl+F9',Compile ,\
  en,'-'		,''	  ,	   ,\
  en,'Debug board'	,''	  ,DbgBoard,\
  en,'System functions' ,''	  ,SysFuncs,\
\
  et,'K�ivita'		,'F9'	  ,Run	   ,\
  et,'Kompileeri'	,'Ctrl+F9',Compile ,\
  et,'-'		,''	  ,	   ,\
  et,'Debug board'	,''	  ,DbgBoard,\
  et,'S�steemi funktsioonid' ,''	  ,SysFuncs

popup_res mm.Encoding,\
  @!,<'CP866  ',0x1A,' CP1251'>,'',CP866.CP1251,\
  @!,<'CP1251 ',0x1A,' CP866' >,'',CP1251.CP866,\
  @!,<'-'		      >,'',	       ,\
  @!,<'CP866  ',0x1A,' KOI8-R'>,'',CP866.KOI8R ,\
  @!,<'KOI8-R ',0x1A,' CP866' >,'',KOI8R.CP866 ,\
  @!,<'-'		      >,'',	       ,\
  @!,<'CP1251 ',0x1A,' KOI8-R'>,'',CP1251.KOI8R,\
  @!,<'KOI8-R ',0x1A,' CP1251'>,'',KOI8R.CP1251

popup_res mm.Options,\
  ru,'���譨� ���...'	     ,'',Appearance  ,\
  ru,'-'		     ,'',	     ,\
  ru,'������᭮� �뤥�����'  ,'',SecureSel   ,\
  ru,'��⮬���᪨� ᪮���' ,'',AutoBrackets,\
  ru,'��⮬���᪨� �����' ,'',AutoIndents ,\
  ru,'����� ⠡����'	     ,'',SmartTabs   ,\
  ru,'��⨬��쭮� ��࠭����','',OptimalFill ,\
  ru,'-'		     ,'',	     ,\
  ru,'����� ��ப'	     ,'',LineNumbers ,\
\
  en,'Appearance...'	     ,'',Appearance  ,\
  en,'-'		     ,'',	     ,\
  en,'Secure selection'      ,'',SecureSel   ,\
  en,'Automatic brackets'    ,'',AutoBrackets,\
  en,'Automatic indents'     ,'',AutoIndents ,\
  en,'Smart tabulation'      ,'',SmartTabs   ,\
  en,'Optimal fill on saving','',OptimalFill ,\
  en,'-'		     ,'',	     ,\
  en,'Line numbers'	     ,'',LineNumbers ,\
\
  et,'V�limus...'	     ,'',Appearance  ,\
  et,'-'		     ,'',	     ,\
  et,'Secure selection'      ,'',SecureSel   ,\
  et,'Automaatsed sulud'     ,'',AutoBrackets,\
  et,'Automaatsed taandread' ,'',AutoIndents ,\
  et,'Tark tabulatsioon'     ,'',SmartTabs   ,\
  et,'Optimaalne t�itmine salvestamisel','',OptimalFill ,\
  et,'-'		     ,'',	     ,\
  et,'Rea numbrid'	     ,'',LineNumbers

lsz s_defname,\
  en,<'Untitled',0>,\
  ru,<'����ﭭ�',0>,\
  et,<'Nimetu',0>

lsz s_modified,\
  ru,'��������',\
  en,'Modified',\
  et,'Muudetud'

lsz s_2filename,\
  ru,'��� 䠩��:',\
  en,'Filename:',\
  et,'Faili nimi:'
lsz s_2open,\
  ru,'������',\
  en,'Open',\
  et,'Ava'
lsz s_2save,\
  ru,'���࠭���',\
  en,'Save',\
  et,'Salvesta'
lsz s_2save_no,\
  ru,'���',\
  en,'No',\
  et,'Ei'
lsz s_2find,\
  ru,'����',\
  en,'Find',\
  et,'Leia'
db ':'
lsz s_2replace,\
  ru,'��������',\
  en,'Replace',\
  et,'Asenda'
db ':'
lsz s_2cancel,\
  ru,'�⬥��',\
  en,'Cancel',\
  et,'T�hista'
lsz s_color,\
  ru,'����: 0x',\
  en,'Color: 0x',\
  et,'V�rv: 0x'
lsz s_tabpos,\
  ru,'��ᯮ������� ��������',\
  en,'Tabs placement',\
  et,'Saki asetus'

lsz s_enter_filename,\
  ru,<'������ ��� 䠩��',0>,\
  en,<'Enter filename',0>,\
  et,<'Sisesta faili nimi',0>

lsz s_ask_save,\
  ru,<'������ ��࠭���?',0>,\
  en,<'Would you like to save?',0>,\
  et,<'Kas soovite salvestada?',0>	; Now correct

lsz s_enter_text_to_find,\
  ru,<'������ ⥪�� ��� ���᪠',0>,\
  en,<'Enter text to find',0>,\
  et,<'Sisesta otsitav tekst',0>

lsz s_enter_text_to_replace,\
  ru,<'������ ⥪�� ��� ������',0>,\
  en,<'Enter text to replace',0>,\
  et,<'Sisesta asendatav tekst',0>

lsz s_text_not_found,\
  ru,<'���⨣��� ����� 䠩��, ⥪�� �� ������',0>,\
  en,<'Reached end of file, text not found',0>,\
  et,<'Faili l�pp, teksti ei leitud',0>

lszc s_fs_error,b,\
  ru,<'������ �����襭� �ᯥ譮 (0)',0>,\
  ru,<'',0>,\
  ru,<'�㭪�� �� �����ন������ ��� ������ 䠩����� ��⥬� (2)',0>,\
  ru,<'�������⭠� 䠩����� ��⥬� (3)',0>,\
  ru,<'',0>,\
  ru,<'���������� ������ 䠩� (5)',0>,\
  ru,<'������ �����襭� �ᯥ譮 (6)',0>,\
  ru,<'���� ��室���� �� �࠭�栬� ����� �ணࠬ�� (7)',0>,\
  ru,<'�� ��᪥ ��� ᢮������� ���� (8)',0>,\
  ru,<'������ FAT 㭨�⮦��� (9)',0>,\
  ru,<'����� ������ (10)',0>,\
  ru,<'�訡�� ���ன�⢠ (11)',0>,\
\
  en,<'Operation executed successfully (0)',0>,\
  en,<'',0>,\
  en,<'Function is not supported for the given filesystem (2)',0>,\
  en,<'Unknown filesystem (3)',0>,\
  en,<'',0>,\
  en,<'Unable to open file (5)',0>,\
  en,<'Operation executed successfully (6)',0>,\
  en,<'Pointer lies outside of application memory (7)',0>,\
  en,<'Disk is full (8)',0>,\
  en,<'FAT table is destroyed (9)',0>,\
  en,<'Access denied (10)',0>,\
  en,<'Device error (11)',0>,\
\
  et,<'Operatsioon k�ivitati edukalt (0)',0>,\
  et,<'',0>,\
  et,<'Failis�steem ei toeta funktsiooni (2)',0>,\
  et,<'Tundmatu failis�steem (3)',0>,\
  et,<'',0>,\
  et,<'Faili ei suudetud avada (5)',0>,\
  et,<'Operatsioon k�ivitatud edukalt (6)',0>,\
  et,<'Viit on v�ljaspool programmi m�lu (7)',0>,\
  et,<'Ketas t�is (8)',0>,\
  et,<'FAT tabel h�vitatud (9)',0>,\
  et,<'Juurdep��s keelatud (10)',0>,\
  et,<'Seadme viga (11)',0>

lszc s_appearance,b,\
  ru,'�����',\
  ru,'���',\
  ru,'����� �뤥�����',\
  ru,'��� �뤥�����',\
  ru,'�������',\
  ru,'��᫠',\
  ru,'��ப�',\
  ru,'�������ਨ',\
  ru,'������� ��ப�',\
  ru,'���࠭�� ��ப�',\
\
  en,'Text',\
  en,'Background',\
  en,'Selection text',\
  en,'Selection background',\
  en,'Symbols',\
  en,'Numbers',\
  en,'Strings',\
  en,'Comments',\
  en,'Modified lines',\
  en,'Saved lines',\
\
  et,'Tekst',\
  et,'Taust',\
  et,'Valitud tekst',\
  et,'Valitud taust',\
  et,'S�mbolid',\
  et,'Numbrid',\
  et,'Stringid',\
  et,'Kommentaarid',\
  et,'Muudetud read',\
  et,'Salvestatud read'

lsz sysfuncs_filename,\
  ru,<'SYSFUNCR.TXT',0>,\
  en,<'SYSFUNCS.TXT',0>,\
  et,<'SYSFUNCET.TXT',0>

sz s_example,'EXAMPLE.ASM'
sz s_still  ,'still'
