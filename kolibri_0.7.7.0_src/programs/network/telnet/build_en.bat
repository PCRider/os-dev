@erase lang.inc
@echo lang fix en >lang.inc
@fasm telnet.asm telnet
@erase lang.inc
@pause