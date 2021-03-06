;
;   DESKTOP CONTEXT MENU
;   written by Ivan Poddubny
;
;   ���� - ���� ����㡭�
;   e-mail: ivan-yar@bk.ru
;
;   Compile with flat assembler
;
include 'lang.inc'
include '..\..\macros.inc'

meos_app_start
code

  mov	eax, 48 		  ; ������� ��⥬�� 梥�
  mov	ebx, 3
  mov	ecx, sc 		  ;  ���� ��������
  mov	edx, sizeof.system_colors ;  � �� ࠧ���
  mcall

  mov	eax,40	     ; ��⠭���� ���� ᮡ�⨩
  mov	ebx,100000b  ; ��� ������� ⮫쪮 ����
  mcall

still:		     ; ������ 横� �᭮����� �����

  mov	eax,10	     ; ��� ᮡ���
  mcall

  mov	eax,37	     ; ����� ������ ������?
  mov	ebx,2
  mcall

  cmp	eax,ebx        ; �᫨ �� �ࠢ��, ������
  jne	still

;---���堫�!---

;  mov   eax,37       ; �� ��� �⫠��� - �᫨ ���� � �窥 (0;0), ���஥���
;  xor   ebx,ebx
;  mcall
;  test  eax,eax      ; ����� � �窥 (0;0), �.�. eax = 0
;  je    exit


  mov	eax,9	     ; ����稬 �᫮ ����ᮢ � ��⥬�
  mov	ebx,procinfo
  xor	ecx,ecx
  mcall

  inc	eax	     ; ⥯��� � eax ᮤ�ন��� �᫮ ����ᮢ + 1
  mov	[processes],eax
  mov	ecx,1

 new_process:
  pushad
  mov	eax,9	     ; ����稬 ���ଠ�� � �����; ����� - � ecx
  mov	ebx,procinfo
  mcall
  mov	eax,37	     ; ���न���� �����
  xor	ebx,ebx
  mcall
  mov	ebx,eax 		 ; eax = cursor_x
  shr	eax,16			 ; ebx = cursor_y
  and	ebx,0xffff
  mov	[curx1],eax		 ; curx1 = cursor_x
  mov	[cury1],ebx		 ; cury1 = cursor_y
; \begin{diamond}[18.09.2006]
; ignore minimized windows
	test	[procinfo.wnd_state], 2
	jnz	ne_goden
; \end{diamond}[18.09.2006]
  mov	eax,[procinfo.box.left]   ; eax = wnd_x_start
  mov	ebx,[procinfo.box.top]	  ; ebx = wnd_y_start

  mov	ecx,[procinfo.box.width]
  add	ecx,eax 		 ; ecx = wnd_x_end
  mov	edx,[procinfo.box.height]
  add	edx,ebx 		 ; ecx = wnd_y_end

  cmp	eax,[curx1]  ; wnd_x_start > cursor_x => ����� ����� ����
  jg	ne_goden
  cmp	ecx,[curx1]  ; wnd_x_end   < cursor_x => ����� �ࠢ�� ����
  jl	ne_goden
  cmp	ebx,[cury1]  ; wnd_y_start > cursor_y => ����� ��� ����
  jg	ne_goden
  cmp	edx,[cury1]  ; wnd_y_end   < cursor_y => ����� ���� ����
  jl	ne_goden

goden:		     ; ���� �� ����� ������-� ����, ���⮬� ��祣� �� ������
  popad
  jmp	still

ne_goden:	     ; ���� �� ᭠�㦨 ��ᬠ�ਢ������ ����, ���⮬�
  popad
  inc	ecx
  cmp	ecx,[processes]
  jl	new_process  ; ���� ᬮਬ ᫥���饥 ����, ���� ����᪠�� ����


@@:		; �������, ���� ���짮��⥫� �� ����⨫ �ࠢ�� ������ ���
  mov	eax,37
  mov	ebx,2	; �㭪�� 37-2:
  mcall    ;   ������ �� ������ ���?
  test	eax,ebx ; �᫨ ����⨫, (eax != 2)
  jz	@f	;   ��� � ��砫� �������� 横��

  mov	eax,5	; ����
  ;mov   ebx,2   ;   ������� 2 ��
  mcall

  jmp	@b	;   � �஢�ਬ ���� �����
@@:

; �᫨ 㦥 �뫮 ����� ����, �㦭� ���������, ���� ��� ���஥���:
@@:
  cmp	[menu_opened],0
  je	@f
  mov	eax,5
  mov	ebx,3  ; ��� 3 ��
  mcall
  jmp	@b
@@:

  mov	eax,51		 ; � ⥯��� ����� ᬥ�� ����᪠�� ����� (��⮪) ����
  mov	ebx,1		 ; ᮧ��� ��⮪ (thread)
  mov	ecx,start_wnd	 ; �窠 �室� ��⮪�
  mov	edx,stack_wnd	 ; ���設� ����� ��� ��⮪�
  mcall

  jmp	still



exit_menu:	      ; �᫨ ��室�� �� ����, ���� ������� � [menu_opened] 0
  mov	[menu_opened],0
exit:		      ; � �� ���, ����� ��室�� �� �᭮����� �����
  or	eax,-1	      ; eax = -1
  mcall




; ����� ������ ����� ����
start_wnd:
  mov	[menu_opened],1
  mov	eax,40	    ; ��⠭���� ���� �������� ᮡ�⨩ ��� �⮣� �����
  mov	ebx,100101b ; ���� + ������ + ����ᮢ��
  mcall

red:
  call	draw_window

still2: 	    ; ������ 横� ����� ����

  mov	eax,10	    ; ��� ᮡ���
  mcall

  cmp	eax,1	    ; ����ᮢ��?
  je	red
  cmp	eax,3	    ; ������?
  je	button
  cmp	eax,6	    ; ����?
  je	mouse

  jmp	still2	    ; ������ � ��砫� �������� 横��


; ���������� ����
mouse:		  ; ����� ���짮��⥫� ������ ������ ���, ���஥���
  mov	eax,37
  mov	ebx,2	  ; ����� ������ ������?
  mcall
  test	eax,eax   ; �������? - ⮣�� �४�᭮! ������ � ����� 横�
  jz	still2
  jmp	exit_menu ; � �᫨ ���-⠪� ������ - ���஥� ����


; ������ ������
button:
  mov	eax,17	      ; ������� �����䨪��� ����⮩ ������
  mcall

  sub	ah,10	      ; �ࠢ������ � 10
  jl	nofuncbtns    ; �᫨ ����� - ����뢠�� ����

  movzx ebx,ah	      ; ����稫� ����� �ணࠬ�� � ᯨ᪥ � ebx
  mov	esi, [startapps + ebx*4]
  mov	edi, start_info.path
  cld
 @@:
  lodsb
  stosb
  test	al, al
  jnz	@b
  mcall 70, start_info

;  mov   eax,5         ; �������, ���� �ணࠬ�� ����������
;  mov   ebx,1         ; � � �� ���� �� �㤥� ���ᮢ��� (��� � ��???)
;  mcall          ; �᪮�������� �� ��ப�, �᫨ � ��� �஡����
		       ; � ���ᮢ���

nofuncbtns:	      ; ����뢠�� ����
  jmp	exit_menu



_BTNS_		  = 6	  ; ������⢮ ������ ("�㭪⮢ ����")

if lang eq ru
  font		  = 0x00000000
  string_length   = 20		; ����� ��ப�
  wnd_x_size	  = 133 	; �ਭ� ����
  title_pos	 = 36 shl 16 + 7
else
  font		  = 0x10000000
  string_length   = 12		; ����� ��ப�
  wnd_x_size	  = 105 	; �ਭ� ����
  title_pos	 = 23 shl 16 + 7
end if

;*******************************
;********  ������ ����  ********
;*******************************

draw_window:

  mov	eax,12		 ; ��稭��� "�ᮢ���"
  mov	ebx,1
  mcall

  mov	eax,[curx1]	 ; ⥪�騥 ���न���� �����
  mov	[curx],eax	 ; ����襬 � ���न���� ����
  mov	eax,[cury1]
  mov	[cury],eax

; ⥯��� �㤥� ����� ���न���� ����, �⮡� ��� �� �ࠩ ��࠭� �� �뫥���
  mov	eax,14		      ; ����稬 ࠧ��� ��࠭�
  mcall
  mov	ebx,eax
  shr	eax,16		      ; � eax - x_screen
  and	ebx,0xffff	      ; � ebx - y_screen
  add	eax,-wnd_x_size       ; eax = [x_screen - �ਭ� ����]
  add	ebx,-_BTNS_*15-21     ; ebx = [y_screen - ���� ����]

  cmp	eax,[curx]
  jg	.okx		      ; �᫨ ���� ᫨誮� ������ � �ࠢ��� ���,
  add	[curx],-wnd_x_size    ; ᤢ���� ��� ����� �� 100
 .okx:

  cmp	ebx, [cury]
  jg	.oky		      ; �� ���⨪��� �筮 ⠪��
  add	[cury], -_BTNS_*15-21
 .oky:

  xor	eax, eax	   ; �㭪�� 0 - ᮧ���� ����
  mov	ebx, [curx]	   ;  ebx = [���न��� �� x] shl 16 + [�ਭ�]
  shl	ebx, 16
  add	ebx, wnd_x_size
  mov	ecx, [cury]	   ;  ecx = [���न��� �� y] shl 16 + [����]
  shl	ecx, 16
  add	ecx, _BTNS_*15+21
  mov	edx, [sc.work]	   ;  梥� ࠡ�祩 ������
  mov	esi, [sc.grab]	   ;  梥� ���������
  or	esi, 0x81000000
  mov	edi, [sc.frame]    ;  梥� ࠬ��
  mcall

  mov	eax, 4		   ; ���������
  mov	ebx, title_pos	  ;  [x] shl 16 + [y]
  mov	ecx, [sc.grab_text];  ���� � 梥� (���)
  or	ecx, 0x10000000
;  add   ecx, -0x333333
  push	ecx
  push	ecx
  xor	edx,edx
.dec_color:
  sub	byte [esp+edx], 0x33
  jae	@f
  mov	byte [esp+edx], 0
@@:
  inc	edx
  jnp	.dec_color
  pop	ecx
  mov	edx, title	  ;  ���� ���������
  mov	esi, title.size   ;  ����� ��������� ("M E N U")
  mcall
  pop	ecx
  add	ebx, 1 shl 16	   ;  ᤢ���� ��ࠢ� �� 1
  mcall

  mov	ebx, 1*65536+wnd_x_size-2  ; ��稭��� ������ ������
  mov	ecx, 20*65536+15
  mov	edx, 10 or 0x40000000 ; ��� 30 ��⠭����� => ������ �� ������

  mov	edi,_BTNS_	     ; ������⢮ ������ (����稪)

 newbtn:		     ; ��砫� 横��
  mov	eax,8		     ;  ᮧ��� ������
  mcall

			     ;  ��襬 ⥪�� �� ������
  pushad		     ;   ᯠᠥ� ॣ�����
  shr	ecx, 16
  and	ebx, 0xffff0000
  add	ebx, ecx	     ;   ebx = [x] shl 16 + [y];
  add	ebx, 10*65536+4      ;   ebx += ᬥ饭�� �⭮�⥫쭮 ��� ������;
  mov	ecx, [sc.work_text]  ;   ���� � 梥�
  or	ecx, font
  add	edx, -10	     ;   edx = ����� ������;
  imul	edx, string_length   ;   edx *= ����� ��ப�;
  add	edx, text	     ;   edx += text;  ⥯��� � edx ���� ��ப�
  mov	esi, string_length   ;   � esi - ����� ��ப�
  mov	eax, 4		     ;   �㭪�� 4 - �뢮� ⥪��
  mcall
  popad

  inc	edx		     ;  ����� ������++;
  add	ecx,15*65536	     ;  㢥��稬 ᬥ饭�� �� y
  dec	edi		     ;  㬥��訬 ����稪
  jnz	newbtn		     ; �᫨ �� ����, ����ਬ ��� ��� ࠧ

  mov	eax,12		     ; �����稫� "�ᮢ���"
  mov	ebx,2
  mcall

ret			     ; ������



; ������ ���������
DATA

  macro strtbl name, [string]
  {
   common
     label name dword
   forward
     local str
     dd str
   forward
     str db string
  }

  strtbl startapps	,\
    <"/sys/PIC4",0>	,\
    <"/sys/DESKTOP",0>	,\
    <"/sys/ICON",0>     ,\
    <"/sys/SETUP",0>	,\
    <"/sys/VRR",0> ,\
    <"/sys/CPU",0> 
    
  sz title, "KolibriOS"

  lsz text,\
    en, 'Background  ',\
    en, 'Desktop     ',\
    en, 'Icon manager',\
    en, 'Device setup',\
    en, 'VRR         ',\
    en, 'Processes   ',\
    \
    ru, '������� �����     ',\
    ru, '����ன�� ����      ',\
    ru, '��ࠢ����� �������� ',\
    ru, '����ன�� ���ன�� ',\
    ru, '����ன�� ������  ',\
    ru, '������            '

start_info:
	.mode	dd	7
		dd	0
	.params dd	0
		dd	0
		dd	0
		db	0
		dd	start_info.path

; �������������������� ������
UDATA
  processes   dd ?		; ������⢮ ����ᮢ � ��⥬�
  curx1       dd ?		; ���न���� �����
  cury1       dd ?
  curx	      dd ?		; ���न���� ���� ����
  cury	      dd ?

  menu_opened db ?		; ����� ���� ��� ���? (1-��, 0-���)

align 4
start_info.path rb 256

  sc	   system_colors	; ��⥬�� 梥�
  procinfo process_information	; ���ଠ�� � �����

  rb 1024			; ���� ��� ���� ���� - 墠�� � 1 ��
  align 32
  stack_wnd:


MEOS_APP_END
; ����� ���������