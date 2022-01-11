#ifndef HLS_GETLASTERROR_STRING_H
#define HLS_GETLASTERROR_STRING_H

//#include <winerr.h>
#include <errhandlingapi.h>
#include "common/string.h"
#include "string_operate/turn/turn_string_windows.h"

inline string GetLastError_string()
{
	return turn_string(GetLastError());
}

inline string GetLastError_string_meaning()
{
	DWORD error=GetLastError();
	if(error==0)
		return "�����ɹ���ɡ�";
	if(error==1)
		return "���ܴ���";
	if(error==2)
		return "ϵͳ�Ҳ���ָ�����ļ���";
	if(error==3)
		return "ϵͳ�Ҳ���ָ����·����";
	if(error==4)
		return "ϵͳ�޷����ļ���";
	if(error==5)
		return "�ܾ����ʡ�";
	if(error==6)
		return "�����Ч��";
	if(error==7)
		return "�洢���ƿ鱻�𻵡�";
	if(error==8)
		return "�洢�ռ䲻�㣬�޷���������";
	if(error==9)
		return "�洢���ƿ��ַ��Ч��";
	if(error==10)
		return "��������";
	if(error==11)
		return "��ͼ���ظ�ʽ����ĳ���";
	if(error==12)
		return "��������Ч��";
	if(error==13)
		return "������Ч��";
	if(error==14)
		return "�洢�����㣬�޷���ɴ˲�����";
	if(error==15)
		return "ϵͳ�Ҳ���ָ������������";
	if(error==16)
		return "�޷�ɾ��Ŀ¼��";
	if(error==17)
		return "ϵͳ�޷����ļ��Ƶ���ͬ����������";
	if(error==18)
		return "û�и����ļ���";
	if(error==19)
		return "������д�뱣����";
	if(error==20)
		return "ϵͳ�Ҳ���ָ�����豸��";
	if(error==21)
		return "�豸δ������";
	if(error==22)
		return "�豸��ʶ������";
	if(error==23)
		return "���ݴ��� (ѭ��������)��";
	if(error==24)
		return "���򷢳����������Ȳ���ȷ��";
	if(error==25)
		return "�������޷��ҳ��������ض������ŵ���λ�á�";
	if(error==26)
		return "�޷�����ָ���Ĵ��̻����̡�";
	if(error==27)
		return "�������Ҳ��������������";
	if(error==28)
		return "��ӡ��ȱֽ��";
	if(error==29)
		return "ϵͳ�޷�д��ָ�����豸��";
	if(error==30)
		return "ϵͳ�޷���ָ�����豸�϶�ȡ��";
	if(error==31)
		return "����ϵͳ�ϵ��豸û�з������á�";
	if(error==32)
		return "�����޷������ļ�����Ϊ��һ����������ʹ�ô��ļ���";
	if(error==33)
		return "�����޷������ļ�����Ϊ��һ�������������ļ���һ���֡�";
	if(error==36)
		return "��������Ĵ��ļ����ࡣ";
	if(error==38)
		return "�����ļ���β��";
	if(error==39)
		return "����������";
	if(error==50)
		return "��֧����������";
	if(error==51)
		return "Զ�̼���������� ��";
	if(error==52)
		return "�������������ظ������ơ�";
	if(error==53)
		return "�Ҳ�������·����";
	if(error==54)
		return "����æ��";
	if(error==55)
		return "ָ����������Դ���豸���ٿ��á�";
	if(error==56)
		return "�ѵ������� BIOS �������ơ�";
	if(error==57)
		return "����������Ӳ������";
	if(error==58)
		return "ָ���ķ������޷���������Ĳ�����";
	if(error==59)
		return "����������������";
	if(error==60)
		return "Զ�������������ݡ�";
	if(error==61)
		return "��ӡ������������";
	if(error==62)
		return "�޷��ڷ������ϻ�����ڱ������ӡ�ļ��Ŀռ䡣";
	if(error==63)
		return "ɾ���Ⱥ��ӡ���ļ���";
	if(error==64)
		return "ָ�������������ٿ��á�";
	if(error==65)
		return "�ܾ�������ʡ�";
	if(error==66)
		return "������Դ���ʹ���";
	if(error==67)
		return "�Ҳ�����������";
	if(error==68)
		return "�������ؼ�����������������ơ�";
	if(error==69)
		return "�������� BIOS �Ự���ơ�";
	if(error==70)
		return "Զ�̷���������ͣ�����������������С�";
	if(error==71)
		return "��ǰ���޷���ͬ��Զ�̼�������ӣ���Ϊ�Ѵﵽ�������������Ŀ���ޡ�";
	if(error==72)
		return "����ָͣ���Ĵ�ӡ��������豸��";
	if(error==80)
		return "�ļ����ڡ�";
	if(error==82)
		return "�޷�����Ŀ¼���ļ���";
	if(error==83)
		return "INT 24 ʧ�ܡ�";
	if(error==84)
		return "�޷�ȡ�ô��������Ĵ洢�ռ䡣";
	if(error==85)
		return "�����豸������ʹ���С�";
	if(error==86)
		return "ָ���������������";
	if(error==87)
		return "��������";
	if(error==88)
		return "�����Ϸ���д�����";
	if(error==89)
		return "ϵͳ�޷��ڴ�ʱ������һ�����̡�";
	if(error==100)
		return "�޷�������һ��ϵͳ�źŵơ�";
	if(error==101)
		return "��һ������ӵ�ж�ռ���źŵơ�";
	if(error==102)
		return "�������źŵ����޷��رա�";
	if(error==103)
		return "�޷��������źŵơ�";
	if(error==104)
		return "�޷����ж�ʱ�����ռ���źŵơ�";
	if(error==105)
		return "���źŵƵ�ǰһ������Ȩ�ѽ�����";
	if(error==107)
		return "����ֹͣ����Ϊ���������δ���롣";
	if(error==108)
		return "������ʹ���У�����һ������������";
	if(error==109)
		return "�ܵ��ѽ�����";
	if(error==110)
		return "ϵͳ�޷���ָ�����豸���ļ���";
	if(error==111)
		return "�ļ���̫����";
	if(error==112)
		return "���̿ռ䲻�㡣";
	if(error==113)
		return "�޷��ٻ���ڲ��ļ��ı�ʶ��";
	if(error==114)
		return "Ŀ���ڲ��ļ��ı�ʶ����ȷ��";
	if(error==117)
		return "Ӧ�ó��������� IOCTL ���ô���";
	if(error==118)
		return "��֤д����л�����ֵ����";
	if(error==119)
		return "ϵͳ��֧����������";
	if(error==120)
		return "�˹���ֻ����ϵͳ֧�֡�";
	if(error==121)
		return "�źŵƳ�ʱʱ���ѵ���";
	if(error==122)
		return "���ݵ�ϵͳ���õ�������̫С��";
	if(error==123)
		return "�ļ�����Ŀ¼�������﷨����ȷ��";
	if(error==124)
		return "ϵͳ���ü������";
	if(error==125)
		return "����û�о�ꡣ";
	if(error==126)
		return "�Ҳ���ָ����ģ�顣";
	if(error==127)
		return "�Ҳ���ָ���ĳ���";
	if(error==128)
		return "û�еȺ���ӽ��̡�";
	if(error==130)
		return "��ͼʹ�ò���(����ԭʼ���� I/O)���Ѵ򿪴��̷������ļ������";
	if(error==131)
		return "��ͼ�ƶ��ļ�ָ�뵽�ļ���ͷ֮ǰ��";
	if(error==132)
		return "�޷���ָ�����豸���ļ��������ļ�ָ�롣";
	if(error==133)
		return "������ǰ�������������������޷�ʹ�� JOIN �� SUBST ���";
	if(error==134)
		return "��ͼ���ѱ��ϲ�����������ʹ�� JOIN �� SUBST ���";
	if(error==135)
		return "��ͼ���ѱ��ϲ�����������ʹ�� JOIN �� SUBST ���";
	if(error==136)
		return "ϵͳ��ͼ���δ�ϲ��������� JOIN��";
	if(error==137)
		return "ϵͳ��ͼ���δ����������� SUBST��";
	if(error==138)
		return "ϵͳ��ͼ���������ϲ����ϲ��������ϵ�Ŀ¼��";
	if(error==139)
		return "ϵͳ��ͼ�����������Ϊ����������ϵ�Ŀ¼��";
	if(error==140)
		return "ϵͳ��ͼ���������ϲ�������������ϵ�Ŀ¼��";
	if(error==141)
		return "ϵͳ��ͼ���������Ϊ�ϲ��������ϵ�Ŀ¼��";
	if(error==142)
		return "ϵͳ�޷��ڴ�ʱ���� JOIN �� SUBST��";
	if(error==143)
		return "ϵͳ�޷����������ϲ��������Ϊ��ͬ�������ϵ�Ŀ¼��";
	if(error==144)
		return "Ŀ¼���Ǹ�Ŀ¼�µ���Ŀ¼��";
	if(error==145)
		return "Ŀ¼�ǿա�";
	if(error==146)
		return "ָ����·�����������ʹ�á�";
	if(error==147)
		return "��Դ���㣬�޷���������";
	if(error==148)
		return "ָ����·���޷��ڴ�ʱʹ�á�";
	if(error==149)
		return "��ͼ���������ϲ������Ϊ��������Ŀ¼����һ�������Ŀ�����������";
	if(error==150)
		return "ϵͳ������Ϣδ�� CONFIG.SYS �ļ���ָ������������١�";
	if(error==151)
		return "Ϊ DosMuxSemWait ָ�����źŵ��¼���������";
	if(error==152)
		return "DosMuxSemWait �������С������ù�����źŵơ�";
	if(error==153)
		return "DosMuxSemWait �嵥����";
	if(error==154)
		return "����ľ�곬��Ŀ���ļ�ϵͳ�ĳ�������";
	if(error==155)
		return "�޷�������һ���̡߳�";
	if(error==156)
		return "���ս����Ѿܾ����źš�";
	if(error==157)
		return "���ѱ��������޷�������";
	if(error==158)
		return "���ѽ��������";
	if(error==159)
		return "�̱߳�ʶ�ĵ�ַ����";
	if(error==160)
		return "���ݵ� DosExecPgm �Ĳ����ַ�������";
	if(error==161)
		return "ָ����·����Ч��";
	if(error==162)
		return "�ź�����ͣ��";
	if(error==164)
		return "�޷���ϵͳ�д���������̡߳�";
	if(error==167)
		return "�޷������ļ�����";
	if(error==170)
		return "�������Դ��ʹ���С�";
	if(error==173)
		return "�����ṩȡ����������������������ԡ�";
	if(error==174)
		return "�ļ�ϵͳ��֧���������͵���С��Ԫ���ġ�";
	if(error==180)
		return "ϵͳ��������Ķκš�";
	if(error==183)
		return "���ļ��Ѵ���ʱ���޷��������ļ���";
	if(error==186)
		return "���ݵı�־����";
	if(error==187)
		return "�Ҳ���ָ����ϵͳ�źŵ����ơ�";
	if(error==196)
		return "����ϵͳ�޷����д�Ӧ�ó���";
	if(error==197)
		return "����ϵͳ��ǰ�����ò������д�Ӧ�ó���";
	if(error==199)
		return "����ϵͳ�޷����д�Ӧ�ó���";
	if(error==200)
		return "����β��ɴ��ڻ���� 64K��";
	if(error==203)
		return "����ϵͳ�Ҳ���������Ļ���ѡ�";
	if(error==205)
		return "���������еĽ���û���źŴ������";
	if(error==206)
		return "�ļ�������չ��̫����";
	if(error==207)
		return "�� 2 ����ջ�ѱ�ռ�á�";
	if(error==208)
		return "û����ȷ�����ļ���ͨ��� * �� ?����ָ��������ļ���ͨ�����";
	if(error==209)
		return "���ڷ��͵��źŴ���";
	if(error==210)
		return "�޷������źŴ������";
	if(error==212)
		return "�����������޷����·��䡣";
	if(error==214)
		return "�����ó����̬����ģ��Ķ�̬����ģ��̫�ࡣ";
	if(error==215)
		return "�޷�Ƕ�׵��� LoadModule��";
	if(error==230)
		return "�ܵ�״̬��Ч��";
	if(error==231)
		return "���еĹܵ�ʵ������ʹ���С�";
	if(error==232)
		return "�ܵ����ڹر��С�";
	if(error==233)
		return "�ܵ�����һ�������κν��̡�";
	if(error==234)
		return "�������ݿ��á�";
	if(error==240)
		return "ȡ���Ự��";
	if(error==254)
		return "ָ������չ��������Ч��";
	if(error==255)
		return "��չ���Բ�һ�¡�";
	if(error==258)
		return "�ȴ��Ĳ�����ʱ��";
	if(error==259)
		return "û�п��õ������ˡ�";
	if(error==266)
		return "�޷�ʹ�ø��ƹ��ܡ�";
	if(error==267)
		return "Ŀ¼����Ч��";
	if(error==275)
		return "��չ�����ڻ������в����á�";
	if(error==276)
		return "װ���ļ�ϵͳ�ϵ���չ�����ļ����𻵡�";
	if(error==277)
		return "��չ���Ա���ļ�������";
	if(error==278)
		return "ָ������չ���Ծ����Ч��";
	if(error==282)
		return "װ����ļ�ϵͳ��֧����չ���ԡ�";
	if(error==288)
		return "��ͼ�ͷŲ��Ǻ��з���ӵ�еĶ��û��ն����г���";
	if(error==298)
		return "�����źŵƵ�������ࡣ";
	if(error==299)
		return "����ɲ��ֵ� ReadProcessMemoty �� WriteProcessMemory ����";
	if(error==300)
		return "�����������󱻾ܾ���";
	if(error==301)
		return "ϵͳ������һ����Ч�Ĳ�������ȷ�ϡ�";
	if(error==487)
		return "��ͼ������Ч�ĵ�ַ��";
	if(error==534)
		return "����������� 32 λ��";
	if(error==535)
		return "�ܵ�����һ����һ���̡�";
	if(error==536)
		return "�Ⱥ�򿪹ܵ���һ�˵Ľ��̡�";
	if(error==994)
		return "�ܾ�������չ���ԡ�";
	if(error==995)
		return "�����߳��˳���Ӧ�ó��������ѷ��� I/O ������";
	if(error==996)
		return "�ص� I/O �¼������ź�״̬�С�";
	if(error==997)
		return "�ص� I/O �����ڽ����С�";
	if(error==998)
		return "�ڴ���������Ч��";
	if(error==999)
		return "��������ҳ�ڲ�����";
	if(error==1001)
		return "�ݹ�̫�ջ�����";
	if(error==1002)
		return "�����޷����ѷ��͵���Ϣ�ϲ�����";
	if(error==1003)
		return "�޷���ɴ˹��ܡ�";
	if(error==1004)
		return "��Ч��־��";
	if(error==1005)
		return "�˾�������ʶ����ļ�ϵͳ����ȷ������������ļ�ϵͳ���������Ѽ��أ��Ҵ˾�δ�𻵡�";
	if(error==1006)
		return "�ļ����ڵľ��ѱ��ⲿ�ı䣬��˴򿪵��ļ�������Ч��";
	if(error==1007)
		return "�޷���ȫ��Ļģʽ����������Ĳ�����";
	if(error==1008)
		return "��ͼ���ò����ڵ����ơ�";
	if(error==1009)
		return "����ע������ݿ��𻵡�";
	if(error==1010)
		return "����ע�������Ч��";
	if(error==1011)
		return "�޷�������ע����";
	if(error==1012)
		return "�޷���ȡ����ע����";
	if(error==1013)
		return "�޷�д������ע����";
	if(error==1014)
		return "ע������ݿ��е�ĳһ�ļ�����ʹ�ü�¼������������ָ����ָ��ɹ���ɡ�";
	if(error==1015)
		return "ע����𻵡�����ע������ݵ�ĳһ�ļ��ṹ�𻵣���ϵͳ���ļ��ڴ�ӳ���𻵣�����Ϊ�����������־ȱ�ٻ��𻵶��޷��ָ��ļ���";
	if(error==1016)
		return "��ע��������� I/O �����ָ�ʧ�ܡ�ע����޷����롢д�����������һ������ע���ϵͳӳ����ļ���";
	if(error==1017)
		return "ϵͳ��ͼ���ػ�ԭ�ļ���ע�����ָ�����ļ�����ע����ļ���ʽ��";
	if(error==1018)
		return "��ͼ�ڱ��Ϊɾ����ע����������в��Ϸ��Ĳ�����";
	if(error==1019)
		return "ϵͳ�޷�����ע�����־��������Ŀռ䡣";
	if(error==1020)
		return "�޷������������ֵ��ע������д����������ӡ�";
	if(error==1021)
		return "�޷����ױ丸���´����ȶ����";
	if(error==1022)
		return "֪ͨ����������������У�����Ϣ��δ���ص����з��Ļ������С���ǰ���з�����ö���ļ������Ҹ��ġ�";
	if(error==1051)
		return "�ѷ���ֹͣ���Ƶ����񣬸÷��������������еķ�����������";
	if(error==1052)
		return "����Ŀؼ��Դ˷�����Ч";
	if(error==1053)
		return "����δ��ʱ��Ӧ�������������";
	if(error==1054)
		return "�޷������˷�����̡߳�";
	if(error==1055)
		return "�����������ݿ⡣";
	if(error==1056)
		return "�����ʵ�����������С�";
	if(error==1057)
		return "�ʻ�����Ч�򲻴��ڣ������������ָ�����ʻ�����Ч��";
	if(error==1058)
		return "�޷���������ԭ��������������û�������������豸û��������";
	if(error==1059)
		return "ָ����ѭ���������档";
	if(error==1060)
		return "ָ���ķ���δ���Ѱ�װ�ķ�����ڡ�";
	if(error==1061)
		return "�����޷��ڴ�ʱ���ܿ�����Ϣ��";
	if(error==1062)
		return "����δ������";
	if(error==1063)
		return "��������޷����ӵ�����������ϡ�";
	if(error==1064)
		return "�������������ʱ���ڷ����з����쳣��";
	if(error==1065)
		return "ָ�������ݿⲻ���ڡ�";
	if(error==1066)
		return "�����ѷ����ض��ķ�������롣";
	if(error==1067)
		return "����������ֹ��";
	if(error==1068)
		return "�����������޷�������";
	if(error==1069)
		return "���ڵ�¼ʧ�ܶ��޷���������";
	if(error==1070)
		return "�����󣬷���ͣ����������ͣ״̬��";
	if(error==1071)
		return "ָ���ķ������ݿ�������Ч��";
	if(error==1072)
		return "ָ���ķ����ѱ��Ϊɾ����";
	if(error==1073)
		return "ָ���ķ����Ѵ��ڡ�";
	if(error==1074)
		return "ϵͳ��ǰ�����µ���Ч�������С�";
	if(error==1075)
		return "������񲻴��ڣ����ѱ����Ϊɾ����";
	if(error==1076)
		return "�ѽ���ʹ�õ�ǰ������Ϊ������Ч�������á�";
	if(error==1077)
		return "�ϴ�����֮����δ������������";
	if(error==1078)
		return "�����������������������ʾ����";
	if(error==1079)
		return "�˷�����ʻ���ͬ��������ͬһ�����ϵ�����������ʻ���";
	if(error==1080)
		return "ֻ��Ϊ Win32 ��������ʧ�ܲ���������Ϊ�����������á�";
	if(error==1081)
		return "������������еĴ���ͷ�����ƹ�������ͬ�����ԣ�������������������ֹ�Ļ���������ƹ������޷������κβ�����";
	if(error==1082)
		return "���������δ���ûָ�����";
	if(error==1083)
		return "���ó��ڸÿ�ִ�г��������е����������ִ�и÷���";
	if(error==1100)
		return "�Ѵ�Ŵ���ʵ�ʽ�β��";
	if(error==1101)
		return "�Ŵ������Ѵ��ļ���ǡ�";
	if(error==1102)
		return "�Ѵ�Ŵ�����̷����Ŀ�ͷ��";
	if(error==1103)
		return "�Ŵ������Ѵ�һ���ļ��Ľ�β��";
	if(error==1104)
		return "�Ŵ��ϲ������κ����ݡ�";
	if(error==1105)
		return "�Ŵ��޷�������";
	if(error==1106)
		return "�ڷ��ʶ��������´Ŵ�ʱ����ǰ�Ŀ��С����ȷ��";
	if(error==1107)
		return "�����شŴ�ʱ���Ҳ���������Ϣ��";
	if(error==1108)
		return "�޷�����ý�嵯�����ܡ�";
	if(error==1109)
		return "�޷�ж�ؽ��ʡ�";
	if(error==1110)
		return "�������еĽ��ʿ����Ѹ��ġ�";
	if(error==1111)
		return "��λ I/O ���ߡ�";
	if(error==1112)
		return "��������û��ý�塣";
	if(error==1113)
		return "�ڶ��ֽڵ�Ŀ�����ҳ�У�û�д� Unicode �ַ�����ӳ�䵽���ַ���";
	if(error==1114)
		return "��̬���ӿ� (DLL) ��ʼ������ʧ�ܡ�";
	if(error==1115)
		return "ϵͳ�ػ����ڽ��С�";
	if(error==1116)
		return "��Ϊû���κν����еĹػ����̣������޷��ж�ϵͳ�ػ���";
	if(error==1117)
		return "��Ϊ I/O �豸���������޷����д�������";
	if(error==1118)
		return "û�д����豸����ʼ���ɹ���������������ж�ء�";
	if(error==1119)
		return "�޷��������������豸�����ж�����(IRQ)���豸��������һ��ʹ�ø� IRQ �������豸�Ѵ򿪡�";
	if(error==1120)
		return "���� I/O ����������һ�����пڵ�д����ɡ�(IOCTL_SERIAL_XOFF_COUNTER �Ѵ��㡣)";
	if(error==1121)
		return "��Ϊ�ѹ���ʱʱ�䣬���Դ��� I/O ������ɡ�(IOCTL_SERIAL_XOFF_COUNTER δ���㡣)";
	if(error==1122)
		return "���������Ҳ��� ID ��ַ��ǡ�";
	if(error==1123)
		return "�������� ID �ַ��������̿������ŵ���ַ�������";
	if(error==1124)
		return "���̿�����������������������ʶ��Ĵ���";
	if(error==1125)
		return "���̿�������������Ĵ����в�һ�µĽ����";
	if(error==1126)
		return "������Ӳ��ʱ������У׼����ʧ�ܣ�������Ȼʧ�ܡ�";
	if(error==1127)
		return "������Ӳ��ʱ�����̲���ʧ�ܣ�������Ȼʧ�ܡ�";
	if(error==1128)
		return "������Ӳ��ʱ����ʹʧ�ܣ����븴λ���̿�������";
	if(error==1129)
		return "�Ѵ�Ŵ���β��";
	if(error==1130)
		return "�������洢�ռ䲻�㣬�޷���������";
	if(error==1131)
		return "����Ǳ�ڵ�����״̬��";
	if(error==1132)
		return "ָ���Ļ�ַ���ļ�ƫ����û���ʵ����롣";
	if(error==1140)
		return "�ı�ϵͳ����״̬�ĳ��Ա���һӦ�ó����������������";
	if(error==1141)
		return "ϵͳ BIOS �ı�ϵͳ����״̬�ĳ���ʧ�ܡ�";
	if(error==1142)
		return "��ͼ��һ�ļ��ϴ�������ϵͳ������������ӡ�";
	if(error==1150)
		return "ָ������Ҫ����µ� Windows �汾��";
	if(error==1151)
		return "ָ�������� Windows �� MS-DOS ����";
	if(error==1152)
		return "ֻ��������ָ�������һ��ʵ����";
	if(error==1153)
		return "��ָ�����������ھɵ� Windows �汾��";
	if(error==1154)
		return "ִ�и�Ӧ�ó�������Ŀ��ļ�֮һ���𻵡�";
	if(error==1155)
		return "û��Ӧ�ó�����˲�����ָ���ļ��й�����";
	if(error==1156)
		return "������ָ�Ӧ�ó���Ĺ����г��ִ��󡣡�";
	if(error==1157)
		return "ִ�и�Ӧ�ó�������Ŀ��ļ�֮һ�޷��ҵ���";
	if(error==1158)
		return "��ǰ������ʹ���� Window �����������ϵͳ��������о����";
	if(error==1159)
		return "��Ϣֻ����ͬ������һ��ʹ�á�";
	if(error==1160)
		return "ָ����ԴԪ��û��ý�塣";
	if(error==1161)
		return "ָ����Ŀ��Ԫ���Ѱ���ý�塣";
	if(error==1162)
		return "ָ����Ԫ�ز����ڡ�";
	if(error==1163)
		return "ָ����Ԫ����δ��ʾ�Ĵ洢��Դ��һ���֡�";
	if(error==1164)
		return "��ʾ�豸��Ҫ���³�ʼ������ΪӲ���д���";
	if(error==1165)
		return "�豸��ʾ�ڳ��Խ�һ������֮ǰ��Ҫ�����";
	if(error==1166)
		return "�豸��ʾ���������Ǵ�״̬��";
	if(error==1167)
		return "�豸û�����ӡ�";
	if(error==1168)
		return "�Ҳ���Ԫ�ء�";
	if(error==1169)
		return "������û��ָͬ������ƥ����";
	if(error==1170)
		return "�ڶ����ϲ�����ָ�������Լ���";
	if(error==1171)
		return "���ݵ� GetMouseMovePoints �ĵ㲻�ڻ������С�";
	if(error==1172)
		return "����(����վ)����û���С�";
	if(error==1173)
		return "�Ҳ����� ID��";
	if(error==1175)
		return "�޷�ɾ��Ҫ���滻���ļ���";
	if(error==1176)
		return "�޷����滻�ļ��Ƶ�Ҫ���滻���ļ���Ҫ���滻���ļ�����ԭ�������ơ�";
	if(error==1177)
		return "�޷����滻�ļ��Ƶ�Ҫ���滻���ļ���Ҫ���滻���ļ��ѱ���������Ϊ�������ơ�";
	if(error==1178)
		return "����ļ�¼��ɾ����";
	if(error==1179)
		return "����ļ�¼���񲻴��ڻ�С�";
	if(error==1180)
		return "�ҵ�һ���ļ������ǿ��ܲ�����ȷ���ļ���";
	if(error==1181)
		return "��־�����־�б�ɾ����";
	if(error==1200)
		return "ָ�����豸����Ч��";
	if(error==1201)
		return "�豸��ǰδ�����ϣ�����Ϊһ����¼���ӡ�";
	if(error==1202)
		return "��ͼ��¼��ǰ�ѱ���¼���豸��";
	if(error==1203)
		return "���κ������ṩ�������ָ��������·����";
	if(error==1204)
		return "ָ���������ṩ����������Ч��";
	if(error==1205)
		return "�޷����������������ļ���";
	if(error==1206)
		return "�������������ļ��𻵡�";
	if(error==1207)
		return "�޷�ö�ٿ����塣";
	if(error==1208)
		return "������չ����";
	if(error==1209)
		return "ָ����������ʽ��Ч��";
	if(error==1210)
		return "ָ���ļ��������ʽ��Ч��";
	if(error==1211)
		return "ָ�����¼�����ʽ��Ч��";
	if(error==1212)
		return "ָ����������ʽ��Ч��";
	if(error==1213)
		return "ָ���ķ�������ʽ��Ч��";
	if(error==1214)
		return "ָ������������ʽ��Ч��";
	if(error==1215)
		return "ָ���Ĺ�������ʽ��Ч��";
	if(error==1216)
		return "ָ���������ʽ��Ч��";
	if(error==1217)
		return "ָ������Ϣ����ʽ��Ч��";
	if(error==1218)
		return "ָ������ϢĿ���ʽ��Ч��";
	if(error==1219)
		return "�ṩ��ƾ�����Ѵ��ڵ�ƾ�ݼ���ͻ��";
	if(error==1220)
		return "��ͼ��������������ĻỰ�����ѶԸ÷�������������ĻỰ��";
	if(error==1221)
		return "��������������������ϵ���һ�������ʹ�á�";
	if(error==1222)
		return "����δ���ӻ�������";
	if(error==1223)
		return "�����ѱ��û�ȡ����";
	if(error==1224)
		return "����Ĳ����޷���ʹ���û�ӳ������򿪵��ļ���ִ�С�";
	if(error==1225)
		return "Զ��ϵͳ�ܾ��������ӡ�";
	if(error==1226)
		return "���������ѱ��ʵ��عر��ˡ�";
	if(error==1227)
		return "���紫���ս��������������ĵ�ַ��";
	if(error==1228)
		return "��ַ��δ�������ս�������";
	if(error==1229)
		return "��ͼ�ڲ����ڵ����������Ͻ��в�����";
	if(error==1230)
		return "��ͼ��ʹ���е����������Ͻ�����Ч�Ĳ�����";
	if(error==1231)
		return "���ܷ�������λ�á��й������ų����ϵ���Ϣ������� Windows ������";
	if(error==1232)
		return "���ܷ�������λ�á��й������ų����ϵ���Ϣ������� Windows ������";
	if(error==1233)
		return "���ܷ�������λ�á��й������ų����ϵ���Ϣ������� Windows ������";
	if(error==1234)
		return "û���κη�������Զ��ϵͳ�ϵ�Ŀ�������ս���ϲ�����";
	if(error==1235)
		return "������ֹ��";
	if(error==1236)
		return "�ɱ���ϵͳ��ֹ�������ӡ�";
	if(error==1237)
		return "�����޷���ɡ�Ӧ�����ԡ�";
	if(error==1238)
		return "��Ϊ�Ѵﵽ���ʻ������ͬʱ���������ƣ������޷����ӷ�������";
	if(error==1239)
		return "��ͼ������ʻ�δ����Ȩ��ʱ���ڵ�¼��";
	if(error==1240)
		return "���ʻ���δ�õ����������վ��¼����Ȩ��";
	if(error==1241)
		return "����Ĳ�������ʹ����������ַ��";
	if(error==1242)
		return "�������Ѿ�ע�ᡣ";
	if(error==1243)
		return "ָ���ķ��񲻴��ڡ�";
	if(error==1244)
		return "��Ϊ�û���δ����֤������ִ����Ҫ��Ĳ�����";
	if(error==1245)
		return "��Ϊ�û���δ��¼���磬����ִ����Ҫ��Ĳ�����ָ���ķ��񲻴��ڡ�";
	if(error==1246)
		return "���ڼ���������";
	if(error==1247)
		return "��ͼ���г�ʼ���������ǳ�ʼ������ɡ�";
	if(error==1248)
		return "û�и���ı����豸����";
	if(error==1249)
		return "ָ����վ�㲻���ڡ�";
	if(error==1250)
		return "����ָ�����Ƶ���������Ѿ����ڡ�";
	if(error==1251)
		return "ֻ�����ӵ���������ʱ���ò�������֧�֡�";
	if(error==1252)
		return "��ʹû�иĶ�������Կ��ҲӦ�õ�����չ��";
	if(error==1253)
		return "ָ�����û�û��һ����Ч�������ļ���";
	if(error==1254)
		return "Microsoft Small Business Server ��֧�ִ˲�����";
	if(error==1300)
		return "�������б����õ���Ȩ��ָ�ɸ����з���";
	if(error==1301)
		return "�ʻ����Ͱ�ȫ��ʶ���ĳЩӳ��δ��ɡ�";
	if(error==1302)
		return "û��Ϊ���ʻ��ر�����ϵͳ������ơ�";
	if(error==1303)
		return "û�п��õļ�����Կ��������һ����֪������Կ��";
	if(error==1304)
		return "����̫���ӣ��޷�ת���� LAN Manager ���롣���ص� LAN Manager ����Ϊ���ַ�����";
	if(error==1305)
		return "�޶�����δ֪��";
	if(error==1306)
		return "���������޶������ǲ����ݵġ�";
	if(error==1307)
		return "�����ȫ��ʶ����ָ��Ϊ�˶���������ߡ�";
	if(error==1308)
		return "�����ȫ��ʶ����ָ��Ϊ�������Ҫ�顣";
	if(error==1309)
		return "��ǰ��δģ��ͻ����߳���ͼ����ģ�����ơ�";
	if(error==1310)
		return "�����δ�����á�";
	if(error==1311)
		return "��ǰû�п��õĵ�¼�������������¼����";
	if(error==1312)
		return "ָ���ĵ�¼�Ự�����ڡ������ѱ���ֹ��";
	if(error==1313)
		return "ָ������Ȩ�����ڡ�";
	if(error==1314)
		return "�ͻ�û���������Ȩ��";
	if(error==1315)
		return "�ṩ�����Ʋ�����ȷ���ʻ�����ʽ��";
	if(error==1316)
		return "ָ�����û��Ѵ��ڡ�";
	if(error==1317)
		return "ָ�����û������ڡ�";
	if(error==1318)
		return "ָ�������Ѵ��ڡ�";
	if(error==1319)
		return "ָ�����鲻���ڡ�";
	if(error==1320)
		return "ָ�����û��ʻ�����ָ����ĳ�Ա��������Ϊ�������Ա�����޷�ɾ��ָ�����顣";
	if(error==1321)
		return "ָ�����û��ʻ�����ָ�����ʻ��ĳ�Ա��";
	if(error==1322)
		return "�޷����û�ɾ�����ʣ���ϵͳ�����ʻ���";
	if(error==1323)
		return "�޷��������롣�ṩ��Ϊ��ǰ�����ֵ����ȷ��";
	if(error==1324)
		return "�޷��������롣�ṩ���������ֵ���������в������ֵ��";
	if(error==1325)
		return "�޷��������롣Ϊ�������ṩ��ֵ�������ַ���ĳ��ȡ������Ի���ʷҪ��";
	if(error==1326)
		return "��¼ʧ��: δ֪���û�����������롣";
	if(error==1327)
		return "��¼ʧ��: �û��ʻ����ơ�";
	if(error==1328)
		return "��¼ʧ��: Υ���ʻ���¼ʱ�����ơ�";
	if(error==1329)
		return "��¼ʧ��: �������û���¼���˼������";
	if(error==1330)
		return "��¼ʧ��: ָ�����ʻ������ѹ��ڡ�";
	if(error==1331)
		return "��¼ʧ��: ���õ�ǰ���ʻ���";
	if(error==1332)
		return "�ʻ����밲ȫ��ʶ�����κ�ӳ����ɡ�";
	if(error==1333)
		return "һ���������ı����û���ʶ��(LUIDs)��";
	if(error==1334)
		return "�޸�����õı����û���ʶ��(LUIDs)��";
	if(error==1335)
		return "���ڸ��ر��÷�����ȫ ID �Ĵμ���Ȩ������Ч��";
	if(error==1336)
		return "���ʿ����б�(ACL)�ṹ��Ч��";
	if(error==1337)
		return "��ȫ ID �ṹ��Ч��";
	if(error==1338)
		return "��ȫ�������ṹ��Ч��";
	if(error==1340)
		return "�޷��������еķ��ʿ����б�(ACL)����ʿ�����Ŀ(ACE)��";
	if(error==1341)
		return "��������ǰ�ѽ��á�";
	if(error==1342)
		return "��������ǰ�����á�";
	if(error==1343)
		return "�ṩ��ʶ����Ű䷢������ֵΪ��Чֵ��";
	if(error==1344)
		return "�޸�����õ��ڴ��Ը��°�ȫ��Ϣ��";
	if(error==1345)
		return "ָ��������Ч����������Ⱥ������Բ����ݡ�";
	if(error==1346)
		return "ָ����ģ�⼶����Ч�� �����ṩ��ģ�⼶����Ч��";
	if(error==1347)
		return "�޷�����������ȫ���ơ�";
	if(error==1348)
		return "�������֤��Ϣ�����Ч��";
	if(error==1349)
		return "���Ƶ����Ͷ��䳢��ʹ�õķ������ʵ���";
	if(error==1350)
		return "�޷����밲ȫ���޹����Ķ��������а�ȫ�Բ�����";
	if(error==1351)
		return "δ�ܴ����������ȡ������Ϣ����������Ϊ��������ʹ�ã������Ƿ��ʱ��ܾ���";
	if(error==1352)
		return "��ȫ�ʻ�������(SAM)�򱾵ذ�ȫ�䷢����(LSA)�������������а�ȫ�����Ĵ���״̬��";
	if(error==1353)
		return "�������а�ȫ�����Ĵ���״̬��";
	if(error==1354)
		return "�˲���ֻ�������Ҫ����������С�";
	if(error==1355)
		return "ָ�����򲻴��ڣ����޷���ϵ��";
	if(error==1356)
		return "ָ�������Ѵ��ڡ�";
	if(error==1357)
		return "��ͼ����ÿ����������������ơ�";
	if(error==1358)
		return "�޷���������������Ϊ�����ϵ����ؽ���ʧ�ܻ����ݽṹ�𻵡�";
	if(error==1359)
		return "�������ڲ�����";
	if(error==1360)
		return "ͨ�÷������Ͱ�������ӳ�䵽��ͨ�����͵ķ��������С�";
	if(error==1361)
		return "��ȫ��������ʽ����ȷ (���Ի�����ص�)��";
	if(error==1362)
		return "�������ֻ�����ڵ�¼������ʹ�á����ý���δע��Ϊһ����¼���̡�";
	if(error==1363)
		return "�޷�ʹ������ʹ���еı�ʶ�����µĻỰ��";
	if(error==1364)
		return "δ֪��ָ����֤���ݰ���";
	if(error==1365)
		return "��¼�Ự���Ǵ������������һ�µ�״̬�С�";
	if(error==1366)
		return "��¼�Ự��ʶ����ʹ���С�";
	if(error==1367)
		return "��¼���������Ч�ĵ�¼����ֵ��";
	if(error==1368)
		return "��ʹ�������ܵ���ȡ����֮ǰ���޷����ɸùܵ�ģ�⡣";
	if(error==1369)
		return "ע���������������״̬������״̬��һ�¡�";
	if(error==1370)
		return "��ȫ�����ݿ��ڲ������𻵡�";
	if(error==1371)
		return "�޷��������ʻ������д˲�����";
	if(error==1372)
		return "�޷������������������д˲�����";
	if(error==1373)
		return "�޷������������û������д˲�����";
	if(error==1374)
		return "�޷�������ɾ���û�����Ϊ��ǰ��Ϊ�û�����Ҫ�顣";
	if(error==1375)
		return "��������Ϊ��Ҫ����ʹ�á�";
	if(error==1376)
		return "ָ���ı����鲻���ڡ�";
	if(error==1377)
		return "ָ�����ʻ������Ǳ�����ĳ�Ա��";
	if(error==1378)
		return "ָ�����ʻ������Ǳ�����ĳ�Ա��";
	if(error==1379)
		return "ָ���ı������Ѵ��ڡ�";
	if(error==1380)
		return "��¼ʧ��: δ�����û��ڴ˼�����ϵ������¼���͡�";
	if(error==1381)
		return "�ѳ����ڵ�һϵͳ�пɱ�����ܵ���������";
	if(error==1382)
		return "���ܵĳ��ȳ����������󳤶ȡ�";
	if(error==1383)
		return "���ذ�ȫ�䷢�������ݿ��ڲ�������һ���ԡ�";
	if(error==1384)
		return "�ڳ��Ե�¼�Ĺ����У��û��İ�ȫ�����Ļ����˹���İ�ȫ��ʶ��";
	if(error==1385)
		return "��¼ʧ��: δ�����û��ڴ˼�����ϵ������¼���͡�";
	if(error==1386)
		return "�����û�����ʱ��Ҫ����������롣";
	if(error==1387)
		return "���ڳ�Ա�����ڣ��޷�����Ա��ӵ��������У�Ҳ�޷��ӱ����齫��ɾ����";
	if(error==1388)
		return "�޷����³�Ա���뵽�������У���Ϊ��Ա���ʻ����ʹ���";
	if(error==1389)
		return "��ָ������İ�ȫ��ʶ��";
	if(error==1390)
		return "���Ĵ��û�����ʱ��Ҫ����������롣";
	if(error==1391)
		return "���� ACL δ�����κοɳм̵������";
	if(error==1392)
		return "�ļ���Ŀ¼�����޷���ȡ��";
	if(error==1393)
		return "���̽ṹ�����޷���ȡ��";
	if(error==1394)
		return "���κ�ָ����¼�Ự���û��Ự�";
	if(error==1395)
		return "���ڷ��ʵķ�����������Ŀ����Ȩ���ơ���ʱ���Ѿ��޷������ӣ�ԭ�����Ѿ�����ɽ��ܵ�������Ŀ���ޡ�";
	if(error==1396)
		return "��¼ʧ��: ��Ŀ���ʻ����Ʋ���ȷ��";
	if(error==1397)
		return "�໥�����֤ʧ�ܡ��÷����������������������ڡ�";
	if(error==1398)
		return "�ڿͻ����ͷ�����֮����һ��ʱ��";
	if(error==1400)
		return "��Ч�Ĵ��ھ����";
	if(error==1401)
		return "��Ч�Ĳ˵������";
	if(error==1402)
		return "��Ч�Ĺ������";
	if(error==1403)
		return "��Ч�ļ�����������";
	if(error==1404)
		return "��Ч�Ĺҹ������";
	if(error==1405)
		return "��Ч�Ķ��ش���λ�ýṹ�����";
	if(error==1406)
		return "�޷��������ϲ��Ӵ��ڡ�";
	if(error==1407)
		return "�Ҳ����������";
	if(error==1408)
		return "��Ч���ڣ���������һ�̡߳�";
	if(error==1409)
		return "�ȼ���ע�ᡣ";
	if(error==1410)
		return "����Ѵ��ڡ�";
	if(error==1411)
		return "��𲻴��ڡ�";
	if(error==1412)
		return "������д򿪵Ĵ��ڡ�";
	if(error==1413)
		return "��Ч������";
	if(error==1414)
		return "��Ч��ͼ������";
	if(error==1415)
		return "ʹ��ר�� DIALOG �����֡�";
	if(error==1416)
		return "�Ҳ����б���ʶ��";
	if(error==1417)
		return "�Ҳ���ͨ���ַ���";
	if(error==1418)
		return "�߳�û�д򿪵ļ����塣";
	if(error==1419)
		return "û��ע���ȼ���";
	if(error==1420)
		return "���ڲ��ǺϷ��ĶԻ����ڡ�";
	if(error==1421)
		return "�Ҳ����ؼ� ID��";
	if(error==1422)
		return "��Ϊû�б༭���ƣ�������Ͽ����Ϣ��Ч��";
	if(error==1423)
		return "���ڲ�����Ͽ�";
	if(error==1424)
		return "�߶ȱ���С�� 256��";
	if(error==1425)
		return "��Ч���豸������(DC)�����";
	if(error==1426)
		return "��Ч�Ĺҽӳ������͡�";
	if(error==1427)
		return "��Ч�Ĺҽӳ���";
	if(error==1428)
		return "û��ģ�����޷����÷Ǳ����Ĺҽӡ�";
	if(error==1429)
		return "�˹ҽӳ���ֻ���������á�";
	if(error==1430)
		return "Journal Hook �����Ѱ�װ��";
	if(error==1431)
		return "�ҽӳ�����δ��װ��";
	if(error==1432)
		return "��һѡ���б�����Ч��Ϣ��";
	if(error==1433)
		return "LB_SETCOUNT ���͵��Ǳ������б��";
	if(error==1434)
		return "���б��֧�� Tab ����ȡ�";
	if(error==1435)
		return "�޷��ٻ�����һ���̴߳����Ķ���";
	if(error==1436)
		return "�Ӵ���û�в˵���";
	if(error==1437)
		return "����û��ϵͳ�˵���";
	if(error==1438)
		return "��Ч����Ϣ�Ի�����ʽ��";
	if(error==1439)
		return "��Ч��ϵͳ��Χ�ڵ� (SPI_*) ������";
	if(error==1440)
		return "��������Ļ��";
	if(error==1441)
		return "���ش���λ�ýṹ�д��ڵ����о�����������ͬ���ϲ㡣";
	if(error==1442)
		return "���ڲ����Ӵ��ڡ�";
	if(error==1443)
		return "��Ч�� GW_* ���";
	if(error==1444)
		return "��Ч���̱߳�ʶ��";
	if(error==1445)
		return "�޷�����Ƕ����ĵ����� (MDI) �����е���Ϣ��";
	if(error==1446)
		return "����ʽ�˵��Ѿ����";
	if(error==1447)
		return "����û�й�������";
	if(error==1448)
		return "��������Χ���ɴ��� MAXLONG��";
	if(error==1449)
		return "�޷���ָ���ķ�ʽ��ʾ��ɾ�����ڡ�";
	if(error==1450)
		return "ϵͳ��Դ���㣬�޷��������ķ���";
	if(error==1451)
		return "ϵͳ��Դ���㣬�޷��������ķ���";
	if(error==1452)
		return "ϵͳ��Դ���㣬�޷��������ķ���";
	if(error==1453)
		return "���㣬�޷��������ķ���";
	if(error==1454)
		return "���㣬�޷��������ķ���";
	if(error==1455)
		return "ҳ���ļ�̫С���޷���ɲ�����";
	if(error==1456)
		return "�Ҳ����˵��";
	if(error==1457)
		return "���̲��־����Ч��";
	if(error==1458)
		return "������ʹ�ùҹ����͡�";
	if(error==1459)
		return "�ò�����Ҫ����ʽ���ڹ���վ��";
	if(error==1460)
		return "���ڳ�ʱʱ���ѹ����ò������ء�";
	if(error==1461)
		return "��Ч�����������";
	if(error==1500)
		return "�¼���־�ļ��𻵡�";
	if(error==1501)
		return "�޷����¼���־�ļ����¼���־����û��������";
	if(error==1502)
		return "�¼���־�ļ�������";
	if(error==1503)
		return "�¼���־�ļ����ڶ�ȡ����ġ�";
	if(error==1601)
		return "�޷����� Windows ��װ�������뼼��֧����Ա��ϵ��ȷ�� Windows ��װ�����Ƿ�ע����ȷ��";
	if(error==1602)
		return "�û�ȡ���˰�װ��";
	if(error==1603)
		return "��װʱ�������ش���";
	if(error==1604)
		return "��װ�ѹ���δ��ɡ�";
	if(error==1605)
		return "�������ֻ�Ե�ǰ��װ�Ĳ�Ʒ��Ч��";
	if(error==1606)
		return "���� ID δע�ᡣ";
	if(error==1607)
		return "��� ID ��δע�ᡣ";
	if(error==1608)
		return "δ֪���ԡ�";
	if(error==1609)
		return "������ڲ���ȷ��״̬��";
	if(error==1610)
		return "�����Ʒ�������������𻵡����뼼��֧����Ա��ϵ��";
	if(error==1611)
		return "��������ﲻ���ڡ�";
	if(error==1612)
		return "�����Ʒ�İ�װ��Դ�޷�ʹ�á�����֤��Դ�Ƿ���ڣ��Ƿ���Է��ʡ�";
	if(error==1613)
		return "Windows ��װ�����޷���װ�����װ������������밲װ���� Windows ��װ�����°汾�� Windows Service Park��";
	if(error==1614)
		return "û��ж�ز�Ʒ��";
	if(error==1615)
		return "SQL ��ѯ�﷨����ȷ�򲻱�֧�֡�";
	if(error==1616)
		return "��¼�ַ��򲻴��ڡ�";
	if(error==1617)
		return "�豸�ѱ�ɾ��.";
	if(error==1618)
		return "���ڽ�����һ����װ���������ڼ��������װ����֮ǰ����Ǹ�������";
	if(error==1619)
		return "δ�ܴ������װ�����������֤������Ƿ���ڣ��Ƿ���Է��ʣ�������Ӧ�ó���Ӧ����ϵ����֤���Ƿ�����Ч�� Windows ��װ����������";
	if(error==1620)
		return "δ�ܴ������װ�����������Ӧ�ó���Ӧ����ϵ����֤���Ƿ�����Ч�� Windows ��װ����������";
	if(error==1621)
		return "���� Windows ��װ�����û�����ʱ�д������뼼��֧����Ա��ϵ��";
	if(error==1622)
		return "�򿪰�װ��־�ļ��Ĵ�������ָ֤������־�ļ�λ���Ƿ���ڣ��Ƿ����д�롣";
	if(error==1623)
		return "��װ����������Բ���ϵͳ֧�֡�";
	if(error==1624)
		return "Ӧ�ñ任ʱ�Ĵ�������ָ֤���ı任·���Ƿ���Ч��";
	if(error==1625)
		return "ϵͳ���Խ�ֹ�����װ������ϵͳ����Ա��ϵ��";
	if(error==1626)
		return "�޷�ִ�к�����";
	if(error==1627)
		return "ִ���ڼ䣬�����������⡣";
	if(error==1628)
		return "ָ������Ч�Ļ�δ֪�ı��";
	if(error==1629)
		return "�ṩ���������Ͳ��ԡ�";
	if(error==1630)
		return "������͵����ݲ���֧�֡�";
	if(error==1631)
		return "Windows ��װ����δ�����������뼼��֧����Ա��ϵ��";
	if(error==1632)
		return "��ʱ�ļ����������޷�ʹ�á�����֤��ʱ�ļ����Ƿ���ڣ��Ƿ����д�롣";
	if(error==1633)
		return "������������Ͳ�֧�ָð�װ������������Ʒ��Ӧ����ϵ��";
	if(error==1634)
		return "���û������̨�������ʹ�á�";
	if(error==1635)
		return "�޷����޲������������֤�޲�������Ƿ���ڣ��Ƿ���Է��ʣ�������Ӧ�ó���Ӧ����ϵ����֤���Ƿ���Windows ��װ������޲��������";
	if(error==1636)
		return "�޷����޲������������Ӧ�ó���Ӧ����ϵ����֤���Ƿ��� Windows ��װ������޲��������";
	if(error==1637)
		return "Windows ��װ�����޷�����������������������밲װ���� Windows ��װ�����°汾�� Windows Service Pack��";
	if(error==1638)
		return "�Ѱ�װ�����Ʒ����һ���汾������汾�İ�װ�޷�������Ҫ���û�ɾ�������Ʒ�����а汾�����á�������塱�ϵġ����/ɾ�����򡱡�";
	if(error==1639)
		return "��Ч�������в������й���ϸ�������а���������� Windows ��װ����� SDK��";
	if(error==1640)
		return "���ն˷���Զ�̻Ự�ڼ䣬ֻ�й���Ա����ӡ�ɾ�������÷����������Ȩ�ޡ������Ҫ�ڷ������ϰ�װ����������������������Ա��ϵ��";
	if(error==1641)
		return "Ҫ��Ĳ����ѳɹ�������Ҫʹ�Ķ���Ч��������������ϵͳ��";
	if(error==1642)
		return "Windows ��װ�����޷���װ�����޲�������Ϊ�������ĳ�����ܻᶪʧ���������޲�������ܸ��´˳����һ����ͬ�汾����ȷ��Ҫ�������ĳ��������ļ�����������������޲���������ȷ�ġ�";
	if(error==1700)
		return "������Ч��";
	if(error==1701)
		return "�󶨾�����Ͳ���ȷ��";
	if(error==1702)
		return "�󶨾����Ч��";
	if(error==1703)
		return "��֧�� RPC Э�����С�";
	if(error==1704)
		return "RPC Э��������Ч��";
	if(error==1705)
		return "�ַ���ͨ��Ψһ��ʶ (UUID) ��Ч��";
	if(error==1706)
		return "�ս���ʽ��Ч��";
	if(error==1707)
		return "�����ַ��Ч��";
	if(error==1708)
		return "�Ҳ����ս�㡣";
	if(error==1709)
		return "��ʱֵ��Ч��";
	if(error==1710)
		return "�Ҳ�������ͨ��Ψһ��ʶ(UUID)��";
	if(error==1711)
		return "����ͨ��Ψһ��ʶ (UUID)��ע�ᡣ";
	if(error==1712)
		return "����ͨ��Ψһ��ʶ(UUID)��ע�ᡣ";
	if(error==1713)
		return "RPC ����������������";
	if(error==1714)
		return "δ�Ǽ��κ�Э�����С�";
	if(error==1715)
		return "RPC ������δ��������";
	if(error==1716)
		return "δ֪�Ĺ��������͡�";
	if(error==1717)
		return "δ֪�Ľ��档";
	if(error==1718)
		return "û���κ����ӡ�";
	if(error==1719)
		return "���κ�Э��˳��";
	if(error==1720)
		return "�޷������ս�㡣";
	if(error==1721)
		return "��Դ���㣬�޷���ɴ˲�����";
	if(error==1722)
		return "RPC �����������á�";
	if(error==1723)
		return "RPC ��������æ�����޷���ɴ˲�����";
	if(error==1724)
		return "����ѡ����Ч��";
	if(error==1725)
		return "�ڴ��߳��У�û��ʹ���е�Զ�̹��̵��á�";
	if(error==1726)
		return "Զ�̹��̵���ʧ�ܡ�";
	if(error==1727)
		return "Զ�̹��̵���ʧ����δ���С�";
	if(error==1728)
		return "Զ�̹��̵���(RPC)Э�����";
	if(error==1730)
		return "RPC ��������֧�ִ����﷨��";
	if(error==1732)
		return "��֧��ͨ��Ψһ��ʶ(UUID)���͡�";
	if(error==1733)
		return "�����Ч��";
	if(error==1734)
		return "����߽���Ч��";
	if(error==1735)
		return "���Ӳ�������Ŀ���ơ�";
	if(error==1736)
		return "�����﷨��Ч��";
	if(error==1737)
		return "��֧�������﷨��";
	if(error==1739)
		return "û�п���������ͨ��Ψһ��ʶ (UUID)�������ַ��";
	if(error==1740)
		return "�ս����һ�ݱ��ݡ�";
	if(error==1741)
		return "δ֪����֤���͡�";
	if(error==1742)
		return "���õ�������̫С��";
	if(error==1743)
		return "�ַ���̫����";
	if(error==1744)
		return "�Ҳ��� RPC Э��˳��";
	if(error==1745)
		return "���̺ų�����Χ��";
	if(error==1746)
		return "�󶨲������κ���֤��Ϣ��";
	if(error==1747)
		return "δ֪����֤����";
	if(error==1748)
		return "δ֪����֤����";
	if(error==1749)
		return "��ȫ��������Ч��";
	if(error==1750)
		return "δ֪����Ȩ����";
	if(error==1751)
		return "��Ŀ��Ч��";
	if(error==1752)
		return "�������ս���޷����в�����";
	if(error==1753)
		return "�ս��ӳ������޸���Ŀ����ս�㡣";
	if(error==1754)
		return "δ�����κν��档";
	if(error==1755)
		return "��Ŀ���Ʋ�������";
	if(error==1756)
		return "�汾ѡ����Ч��";
	if(error==1757)
		return "û��������Ա��";
	if(error==1758)
		return "û������δ������";
	if(error==1759)
		return "�ӿ�û���ҵ���";
	if(error==1760)
		return "��Ŀ�Ѵ��ڡ�";
	if(error==1761)
		return "�Ҳ�����Ŀ��";
	if(error==1762)
		return "�޿��õ����Ʒ���";
	if(error==1763)
		return "�����ַ����Ч��";
	if(error==1764)
		return "��֧������Ĳ�����";
	if(error==1765)
		return "�޿��õİ�ȫ������������ģ�⡣";
	if(error==1766)
		return "Զ�̹��̵���(RPC)�з����ڲ�����";
	if(error==1767)
		return "RPC ��������ͼ�����������";
	if(error==1768)
		return "RPC �������з�����ַ����";
	if(error==1769)
		return "RPC �������ϵĸ����������������������";
	if(error==1770)
		return "RPC �������Ϸ����������硣";
	if(error==1771)
		return "RPC �������Ϸ����������硣";
	if(error==1772)
		return "�Զ�����󶨵Ŀ��� RPC �������б������ꡣ";
	if(error==1773)
		return "�޷����ַ�������ļ���";
	if(error==1774)
		return "�����ַ��������ļ�����512 �ֽڡ�";
	if(error==1775)
		return "��Զ�̹��̵���ʱ�����յ������ľ���ӿͻ����ݵ�������";
	if(error==1777)
		return "��Զ�̹��̵���ʱ�������ľ���Ѹ��ġ�";
	if(error==1778)
		return "���ݵ�Զ�̹��̵��õİ󶨾���������";
	if(error==1779)
		return "�н����޷����Զ�̹��̵��þ����";
	if(error==1780)
		return "���ݿ�����ָ�뵽�н��塣";
	if(error==1781)
		return "�о�ֵ������Χ��";
	if(error==1782)
		return "�ֽڼ���̫С��";
	if(error==1783)
		return "�н�����յ������ݡ�";
	if(error==1784)
		return "�ṩ������������û���������Ч��";
	if(error==1785)
		return "����ý���޷�ʶ�𡣿���δ����ʽ����";
	if(error==1786)
		return "����վû�����λ��ܡ�";
	if(error==1787)
		return "�������ϵİ�ȫ���ݿ�û�д˹���վ���ι�ϵ�ļ�����ʻ���";
	if(error==1788)
		return "����������������ι�ϵʧ�ܡ�";
	if(error==1789)
		return "�˹���վ�����������ι�ϵʧ�ܡ�";
	if(error==1790)
		return "�����¼ʧ�ܡ�";
	if(error==1791)
		return "���̵߳�Զ�̹��̵������ڽ����С�";
	if(error==1792)
		return "��ͼ��¼�����������¼����û��������";
	if(error==1793)
		return "�û��ʻ����ڡ�";
	if(error==1794)
		return "ת�������ѱ�ռ�����޷�ж�ء�";
	if(error==1795)
		return "ָ���Ĵ�ӡ�����������Ѱ�װ��";
	if(error==1796)
		return "ָ���Ķ˿�δ֪��";
	if(error==1797)
		return "δ֪�Ĵ�ӡ����������";
	if(error==1798)
		return "δ֪�Ĵ�ӡ����������";
	if(error==1799)
		return "ָ���ķָ�ҳ�ļ���Ч��";
	if(error==1800)
		return "ָ�������ȼ���Ч��";
	if(error==1801)
		return "��ӡ������Ч��";
	if(error==1802)
		return "��ӡ���Ѵ��ڡ�";
	if(error==1803)
		return "��ӡ��������Ч��";
	if(error==1804)
		return "ָ��������������Ч��";
	if(error==1805)
		return "ָ���Ļ�����Ч��";
	if(error==1806)
		return "û�и���İ󶨡�";
	if(error==1807)
		return "�����ʻ�Ϊ��������ʻ�����ʹ������ȫ���û��ʻ��򱾵��û��ʻ���������̨��������";
	if(error==1808)
		return "�����ʻ���һ��������ʻ���ʹ������ȫ���û��ʻ��򱾵��û��ʻ������ʴ˷�������";
	if(error==1809)
		return "��ʹ�õ��ʻ�Ϊ�����������ʻ���ʹ������ȫ���û��ʻ��򱾵��û��ʻ������ʴ˷�������";
	if(error==1810)
		return "ָ��������ƻ�ȫ��ʶ(SID)������������Ϣ��һ�¡�";
	if(error==1811)
		return "��������ʹ�������޷�ж�ء�";
	if(error==1812)
		return "ָ����ӳ���ļ���������Դ����";
	if(error==1813)
		return "�Ҳ���ӳ���ļ���ָ������Դ���͡�";
	if(error==1814)
		return "�Ҳ���ӳ���ļ���ָ������Դ����";
	if(error==1815)
		return "�Ҳ���ӳ���ļ���ָ������Դ���Ա�ʶ��";
	if(error==1816)
		return "���㣬�޷���������";
	if(error==1817)
		return "δ�Ǽ��κν��档";
	if(error==1818)
		return "Զ�̹��̵��ñ�ȡ����";
	if(error==1819)
		return "�󶨾��������������Ҫ����Ϣ��";
	if(error==1820)
		return "��Զ�̹��̵��ù�����ͨѶʧ�ܡ�";
	if(error==1821)
		return "��֧���������֤����";
	if(error==1822)
		return "δ�Ǽ��κ������ơ�";
	if(error==1823)
		return "ָ���Ĵ�������Ч�� Windows RPC �����롣";
	if(error==1824)
		return "������һ��ֻ���ⲿ���������Ч�� UUID��";
	if(error==1825)
		return "����һ����ȫ�����еĴ���";
	if(error==1826)
		return "�߳�δȡ����";
	if(error==1827)
		return "��Ч�ı���/������������";
	if(error==1828)
		return "���л���װ�İ汾�����ݡ�";
	if(error==1829)
		return "RPC �н���İ汾�����ݡ�";
	if(error==1830)
		return "RPC �ܵ�������Ч�����𻵡�";
	if(error==1831)
		return "��ͼ�� RPC �ܵ�����Ͻ�����Ч������";
	if(error==1832)
		return "����֧�ֵ� RPC �ܵ��汾��";
	if(error==1898)
		return "�Ҳ��������Ա��";
	if(error==1899)
		return "�޷������ս��ӳ������ݿ��";
	if(error==1900)
		return "����ͨ��Ψһ��ʶ (UUID) Ϊ nil UUID��";
	if(error==1901)
		return "ָ����ʱ����Ч��";
	if(error==1902)
		return "ָ���ĸ�ʽ������Ч��";
	if(error==1903)
		return "ָ���ĸ�ʽ��С��Ч��";
	if(error==1904)
		return "ָ���Ĵ�ӡ��������Ⱥ���";
	if(error==1905)
		return "��ɾ��ָ���Ĵ�ӡ����";
	if(error==1906)
		return "��ӡ����״̬��Ч��";
	if(error==1907)
		return "�ڵ�һ�ε�¼֮ǰ����������û����롣";
	if(error==1908)
		return "�Ҳ�����������������";
	if(error==1909)
		return "���õ��ʻ���ǰ���������ҿ����޷���¼��";
	if(error==1910)
		return "û�з���ָ���Ĵ˶��󵼳���";
	if(error==1911)
		return "û�з���ָ���Ķ���";
	if(error==1912)
		return "û�з���ָ���Ķ����������";
	if(error==1913)
		return "һЩ����������ͣ�������󻺳����ڡ�";
	if(error==1914)
		return "��Ч���첽Զ�̹��̵��þ����";
	if(error==1915)
		return "����������첽 RPC ���þ������ȷ��";
	if(error==1916)
		return "RPC �ܵ������Ѿ��رա�";
	if(error==1917)
		return "�� RPC �������֮ǰȫ���Ĺܵ����Ѵ�����ɡ�";
	if(error==1918)
		return "û���������õ��������� RPC �ܵ���";
	if(error==1919)
		return "�������û�п��õ�վ������";
	if(error==1920)
		return "ϵͳ�޷����ʴ��ļ���";
	if(error==1921)
		return "ϵͳ�޷���ʶ�ļ�����";
	if(error==1922)
		return "��Ŀ������Ҫ�����͡�";
	if(error==1923)
		return "�޷������ж���� UUID ������ָ�����";
	if(error==1924)
		return "�޷������浼����ָ�����";
	if(error==1925)
		return "�޷����ָ���������ļ��";
	if(error==1926)
		return "�޷����ָ���������ļ�Ԫ�ء�";
	if(error==1927)
		return "�޷�ɾ��ָ���������ļ�Ԫ�ء�";
	if(error==1928)
		return "�޷������Ԫ�ء�";
	if(error==1929)
		return "�޷�ɾ����Ԫ�ء�";
	if(error==2000)
		return "��Ч�����ظ�ʽ��";
	if(error==2001)
		return "ָ��������������Ч��";
	if(error==2002)
		return "������ʽ��������ԶԴ˲�����Ч��";
	if(error==2003)
		return "��֧�������ͼԪ������";
	if(error==2004)
		return "��֧������ı任������";
	if(error==2005)
		return "��֧������ļ��в�����";
	if(error==2010)
		return "ָ������ɫ����ģ����Ч��";
	if(error==2011)
		return "�ƶ�����ɫ�ļ�������Ч��";
	if(error==2012)
		return "�Ҳ���ָ���ı�ʶ��";
	if(error==2013)
		return "�Ҳ�������ı�ʶ��";
	if(error==2014)
		return "ָ���ı�ʶ�Ѿ����ڡ�";
	if(error==2015)
		return "ָ������ɫ�ļ��������κ��豸������ء�";
	if(error==2016)
		return "�Ҳ�����ָ������ɫ�ļ�����";
	if(error==2017)
		return "ָ������ɫ�ռ���Ч��";
	if(error==2018)
		return "ͼ����ɫ����û��������";
	if(error==2019)
		return "��ɾ������ɫ����ʱ��һ������";
	if(error==2020)
		return "��ָ������ɫ������Ч��";
	if(error==2021)
		return "��ָ���ı任��λͼ����ɫ�ռ䲻ƥ�䡣";
	if(error==2022)
		return "��ָ����������ɫ�����������ļ��в����ڡ�";
	if(error==2102)
		return "û�а�װ����վ��������";
	if(error==2103)
		return "�޷���λ��������";
	if(error==2104)
		return "�����ڲ����������޷����ʹ����ڴ�Ρ�";
	if(error==2105)
		return "������Դ���㡣";
	if(error==2106)
		return "����վ��֧�����������";
	if(error==2107)
		return "�豸û�����ӡ�";
	if(error==2108)
		return "���������ѳɹ�������Ҫ��ʾ�û�����һ����ͬ��ԭʼָ�������롣";
	if(error==2114)
		return "û����������������";
	if(error==2115)
		return "���пա�";
	if(error==2116)
		return "�豸��Ŀ¼�����ڡ�";
	if(error==2117)
		return "�޷����ض������Դ��ִ�����������";
	if(error==2118)
		return "�����Ѿ�����";
	if(error==2119)
		return "��������ǰ�޷��ṩ�������Դ��";
	if(error==2121)
		return "����Ҫ�����Ŀ������������ޡ�";
	if(error==2122)
		return "�Եȷ���ֻ֧������ͬʱ�������û� ��";
	if(error==2123)
		return "API ���ػ�����̫С��";
	if(error==2127)
		return "Զ�� API ����";
	if(error==2131)
		return "�򿪻��ȡ�����ļ�ʱ����";
	if(error==2136)
		return "����һ���������";
	if(error==2137)
		return "����վ�����״̬��һ�¡�������������վ����֮ǰ���������������������";
	if(error==2138)
		return "����վ����û��������";
	if(error==2139)
		return "������Ϣ�����á�";
	if(error==2140)
		return "���� Windows 2000 �ڲ�����";
	if(error==2141)
		return "������û������������";
	if(error==2142)
		return "Զ�̷�������֧������� API��";
	if(error==2143)
		return "�¼�����Ч��";
	if(error==2144)
		return "�������Ѿ��д˼�������������������������";
	if(error==2146)
		return "������Ϣ���Ҳ���ָ���������";
	if(error==2147)
		return "������Ϣ���Ҳ���ָ���Ĳ�����";
	if(error==2149)
		return "�����ļ�����һ��������̫����";
	if(error==2150)
		return "��ӡ�������ڡ�";
	if(error==2151)
		return "��ӡ��ҵ�����ڡ�";
	if(error==2152)
		return "��ӡ��Ŀ���Ҳ�����";
	if(error==2153)
		return "��ӡ��Ŀ���Ѿ����ڡ�";
	if(error==2154)
		return "��ӡ�������Ѿ����ڡ�";
	if(error==2155)
		return "�޷���������Ĵ�ӡ����";
	if(error==2156)
		return "�޷���������Ĵ�ӡ��ҵ��";
	if(error==2157)
		return "�޷���������Ĵ�ӡ��Ŀ�ꡣ";
	if(error==2158)
		return "�˴�ӡ��Ŀ�괦�ڿ����У������ܿ��Ʋ�����";
	if(error==2159)
		return "�ˡ���ӡ��Ŀ�����󡱰�����Ч�Ŀ��ƺ�����";
	if(error==2160)
		return "��ӡ�������û����Ӧ��";
	if(error==2161)
		return "��̨�������û�����С�";
	if(error==2162)
		return "��ӡĿ�굱ǰ��״�����޷�ִ�����������";
	if(error==2163)
		return "��ӡ�����е�ǰ��״�����޷�ִ�����������";
	if(error==2164)
		return "��ӡ��ҵ��ǰ��״�����޷�ִ�����������";
	if(error==2165)
		return "�޷�Ϊ��̨�����������ڴ档";
	if(error==2166)
		return "�豸�������򲻴��ڡ�";
	if(error==2167)
		return "��ӡ�������֧�������������͡�";
	if(error==2168)
		return "û�а�װ��ӡ�������";
	if(error==2180)
		return "�����������ݿ⡣";
	if(error==2181)
		return "�����������";
	if(error==2182)
		return "����ķ����Ѿ�������";
	if(error==2183)
		return "�������û����Ӧ���Ʋ�����";
	if(error==2184)
		return "������δ������";
	if(error==2185)
		return "��������Ч��";
	if(error==2186)
		return "����û����Ӧ���ƹ��ܡ�";
	if(error==2187)
		return "������ƴ���æµ״̬��";
	if(error==2188)
		return "�����ļ�������Ч�ķ����������";
	if(error==2189)
		return "�ڵ�ǰ��״�����޷����Ʒ���";
	if(error==2190)
		return "�����쳣��ֹ��";
	if(error==2191)
		return "��������޷���������� \"��ͣ\" �� \"ֹͣ\" ������";
	if(error==2192)
		return "������ơ��ƻ������ڡ��ƻ������Ҳ�����������";
	if(error==2193)
		return "�޷���ȡ������Ƽƻ�����ܵ���";
	if(error==2194)
		return "�޷������·�����̡߳�";
	if(error==2200)
		return "�˹���վ�Ѿ���¼����������";
	if(error==2201)
		return "����վû�е�¼����������";
	if(error==2202)
		return "ָ�����û�����Ч��";
	if(error==2203)
		return "���������Ч��";
	if(error==2204)
		return "��¼������û�������Ϣ������";
	if(error==2205)
		return "��¼������û�������Ϣ������";
	if(error==2206)
		return "ע��������û��ɾ����Ϣ������";
	if(error==2207)
		return "ע��������û��ɾ����Ϣ������";
	if(error==2209)
		return "��ͣ�����¼��";
	if(error==2210)
		return "���ĵ�¼������������ͻ��";
	if(error==2211)
		return "������û��������ȷ���û�·����";
	if(error==2212)
		return "���ػ����е�¼�ű�ʱ����";
	if(error==2214)
		return "û��ָ����¼��������������ĵ�¼״̬�ǵ���������";
	if(error==2215)
		return "��¼�������Ҳ�����";
	if(error==2216)
		return "�˼�����Ѿ���һ����¼��";
	if(error==2217)
		return "��¼�������޷���֤��¼��";
	if(error==2219)
		return "��ȫ���ݿ��Ҳ�����";
	if(error==2220)
		return "�����Ҳ�����";
	if(error==2221)
		return "�û����Ҳ�����";
	if(error==2222)
		return "��Դ���Ҳ�����";
	if(error==2223)
		return "���Ѿ����ڡ�";
	if(error==2224)
		return "�ʻ��Ѿ����ڡ�";
	if(error==2225)
		return "��Դʹ��Ȩ���嵥�Ѿ����ڡ�";
	if(error==2226)
		return "�˲���ֻ���ڸ���������������ִ�С�";
	if(error==2227)
		return "��ȫ���ݿ�û��������";
	if(error==2228)
		return "�û��ʻ����ݿ��е�����̫�ࡣ";
	if(error==2229)
		return "���� I/O ʧ�ܡ�";
	if(error==2230)
		return "�Ѿ�����ÿ����Դ 64 ����Ŀ�����ơ�";
	if(error==2231)
		return "����ɾ�����Ự���û���";
	if(error==2232)
		return "�ϲ�Ŀ¼�Ҳ�����";
	if(error==2233)
		return "�޷���ӵ���ȫ���ݿ�Ự���ٻ���Ρ�";
	if(error==2234)
		return "������������ڴ����������ִ�С�";
	if(error==2235)
		return "�û��ʻ����ݿ�Ự���ٻ���û�м�¼���û���";
	if(error==2236)
		return "�û��Ѿ����ڴ��顣";
	if(error==2237)
		return "�û������ڴ��顣";
	if(error==2238)
		return "���û��ʻ���δ���塣";
	if(error==2239)
		return "���û��ʻ��ѹ��ڡ�";
	if(error==2240)
		return "���û����ôӴ˹���վ��¼���硣";
	if(error==2241)
		return "��ʱ�������û���¼���硣";
	if(error==2242)
		return "���û��������Ѿ����ڡ�";
	if(error==2243)
		return "���û��������޷����ġ�";
	if(error==2244)
		return "�����޷�ʹ�ô����롣";
	if(error==2245)
		return "���벻����������Ե���Ҫ�������С���볤�ȡ����븴���Ժ�������ʷ������";
	if(error==2246)
		return "���û���������������ã����ڲ��ܸ��ġ�";
	if(error==2247)
		return "��ȫ���ݿ����𻵡�";
	if(error==2248)
		return "����Ҫ���´˸������Ƶ�����/���ذ�ȫ���ݿ⡣";
	if(error==2249)
		return "�˸������Ƶ����ݿ��ѹ�ʱ����ͬ���������е����ݡ�";
	if(error==2250)
		return "���������Ӳ����ڡ�";
	if(error==2251)
		return "�� asg_type ��Ч��";
	if(error==2252)
		return "���豸��ǰ���ڹ����С�";
	if(error==2270)
		return "��������޷���Ϊ��Ϣ������ӡ������Ͽ����Ѿ��д����ơ�";
	if(error==2271)
		return "��ʹ�����Ѿ�������";
	if(error==2272)
		return "��ʹ��������ʧ�ܡ�";
	if(error==2273)
		return "�������Ҳ�������Ϣ������";
	if(error==2274)
		return "����Ϣ�����Ѿ�ת����ȥ��";
	if(error==2275)
		return "�Ѿ�����˴���Ϣ�����������Ա�ת����";
	if(error==2276)
		return "����Ϣ�������ڱ��ش��ڡ�";
	if(error==2277)
		return "��ӵ���Ϣ�����Ѿ�������Ŀ���ޡ�";
	if(error==2278)
		return "�޷�ɾ�����������";
	if(error==2279)
		return "��Ϣ�޷�ת���ص�ͬһ������վ��";
	if(error==2280)
		return "����Ϣ����������";
	if(error==2281)
		return "��Ϣ�Ѿ����ͳ�ȥ�������ռ����Ѿ���ͣ��ʹ����";
	if(error==2282)
		return "��Ϣ�Ѿ����ͳ�ȥ������δ�յ���";
	if(error==2283)
		return "��Ϣ������ǰ����ʹ���С����Ժ�Ƭ�����ԡ�";
	if(error==2284)
		return "��ʹ������δ������";
	if(error==2285)
		return "�����Ʋ��ڱ��ؼ�����ϡ�";
	if(error==2286)
		return "�������Ҳ���ת������Ϣ������";
	if(error==2287)
		return "Զ��ͨѶվ����Ϣ�������Ѿ����ˡ�";
	if(error==2288)
		return "�˱�������Ϣ��ǰû����ת���С�";
	if(error==2289)
		return "�㲥����Ϣ���ضϡ�";
	if(error==2294)
		return "�豸����Ч��";
	if(error==2295)
		return "д�����";
	if(error==2297)
		return "�����ϵ���Ϣ�����ظ���";
	if(error==2298)
		return "����Ϣ���������Ժ�ɾ����";
	if(error==2299)
		return "û�д����е�����ɾ����Ϣ������";
	if(error==2300)
		return "��������޷���ʹ�ö�������ļ������ִ�С�";
	if(error==2310)
		return "�˹������Դ�����ڡ�";
	if(error==2311)
		return "�豸û�й���";
	if(error==2312)
		return "���˼�������ĻỰ�����ڡ�";
	if(error==2314)
		return "û���ô�ʶ��Ŵ򿪵��ļ���";
	if(error==2315)
		return "ִ��Զ�̹�������ʧ�ܡ�";
	if(error==2316)
		return "��Զ����ʱ�ļ�ʧ�ܡ�";
	if(error==2317)
		return "��Զ�̹�������ص������Ѿ����ضϳ� 64K��";
	if(error==2318)
		return "���豸�޷�ͬʱ����Ϊ��̨������Դ�ͷǺ�̨������Դ��";
	if(error==2319)
		return "�������嵥�е���Ϣ���ܲ���ȷ";
	if(error==2320)
		return "������ڴ���δ���ڻ״̬";
	if(error==2321)
		return "��ɾ������֮ǰ����Ҫ���ù���ӷֲ�ʽ�ļ�ϵͳ��ɾ����";
	if(error==2331)
		return "�޷��ڴ��豸ִ���������";
	if(error==2332)
		return "���豸�޷�����";
	if(error==2333)
		return "���豸δ�򿪡�";
	if(error==2334)
		return "���豸���嵥��Ч��";
	if(error==2335)
		return "�������ȼ���Ч��";
	if(error==2337)
		return "û���κι����ͨѶ�豸��";
	if(error==2338)
		return "ָ���Ķ��в����ڡ�";
	if(error==2340)
		return "���豸�嵥��Ч��";
	if(error==2341)
		return "������豸��Ч��";
	if(error==2342)
		return "��̨�����������ʹ�ô��豸��";
	if(error==2343)
		return "���豸�Ѿ�������ͨѶ�豸��ʹ�á�";
	if(error==2351)
		return "�˼��������Ч��";
	if(error==2354)
		return "ָ�����ַ�����ǰ׺̫����";
	if(error==2356)
		return "��·����ɲ�����Ч��";
	if(error==2357)
		return "�޷��ж��������͡�";
	if(error==2362)
		return "���ͻ�����������";
	if(error==2370)
		return "�����ļ����ó��� 64K��";
	if(error==2371)
		return "��ʼƫ����Խ�硣";
	if(error==2372)
		return "ϵͳ�޷�ɾ����ǰ��������Դ�����ӡ�";
	if(error==2373)
		return "ϵͳ�޷��������ļ��е������С�";
	if(error==2374)
		return "���������ļ�ʱ����/";
	if(error==2375)
		return "���������ļ�ʱ����ֻ���ݵر����������ļ���";
	if(error==2378)
		return "����־�ļ���ǰ�����ζ�ȡ֮���Ѿ������仯��";
	if(error==2380)
		return "��Դ·����������Ŀ¼��";
	if(error==2381)
		return "��Դ·����Ч��";
	if(error==2382)
		return "Ŀ��·����Ч��";
	if(error==2383)
		return "Դ·����Ŀ��·��������ͬ�ķ�������";
	if(error==2385)
		return "����� Run ������������ͣ��";
	if(error==2389)
		return "�� Run ������ͨѶʱ����";
	if(error==2391)
		return "������̨����ʱ����";
	if(error==2392)
		return "�Ҳ��������ӵĹ�����Դ��";
	if(error==2400)
		return "LAN ������������Ч��";
	if(error==2401)
		return "�������������ļ��򿪻��������";
	if(error==2402)
		return "ʹ���е������Դ��ڡ�";
	if(error==2403)
		return "�˹�������������Ч��";
	if(error==2404)
		return "�豸���ɻ����ʹ�ã��޷��Ͽ���";
	if(error==2405)
		return "�������������ڱ���ʹ�á�";
	if(error==2430)
		return "ָ���Ŀͻ��Ѿ���ָ�����¼�ע�ᡣ";
	if(error==2431)
		return "������������";
	if(error==2432)
		return "�����ľ���������Ч�򲻴��ڡ�";
	if(error==2433)
		return "������������Ч��";
	if(error==2434)
		return "�û��ĵ�¼ʱ�䳤�̲��ٺϷ��������Ѿ�ɾ���û���÷������ĻỰ��";
	if(error==2440)
		return "��־�ļ���û������ļ�¼�š�";
	if(error==2450)
		return "�û��ʻ����ݿ�û����ȷ���á�";
	if(error==2451)
		return "�� Netlogon ������������ʱ��������ִ�����������";
	if(error==2452)
		return "��������޷������Ĺ����ʻ���ִ�С�";
	if(error==2453)
		return "�Ҳ�����������������";
	if(error==2454)
		return "�޷����ô��û��ĵ�¼��Ϣ��";
	if(error==2455)
		return "Netlogon ������δ������";
	if(error==2456)
		return "�޷���ӵ��û��ʻ����ݿ⡣";
	if(error==2457)
		return "�˷�������ʱ���������������ʱ�Ӳ�һ�¡�";
	if(error==2458)
		return "��⵽���벻ƥ�䡣";
	if(error==2460)
		return "������ʶ����û��ָ����Ч�ķ�������";
	if(error==2461)
		return "�Ự��ʶû��ָ����Ч�ĻỰ��";
	if(error==2462)
		return "����ʶ����û��ָ����Ч�����ӡ�";
	if(error==2463)
		return "���÷����������޷��ټ��������";
	if(error==2464)
		return "�������Ѿ�����֧�ֵĻỰ��Ŀ���ޡ�";
	if(error==2465)
		return "�������Ѿ�����֧�ֵ�������Ŀ���ޡ�";
	if(error==2466)
		return "�������򿪵��ļ��������ޣ��޷��򿪸����ļ���";
	if(error==2467)
		return "��̨������û�еǼ��滻�ķ�������";
	if(error==2470)
		return "���õͼ��� API (Զ�̹���Э��)��";
	if(error==2480)
		return "UPS �����޷����� UPS ��������";
	if(error==2481)
		return "UPS �������ô���";
	if(error==2482)
		return "UPS �����޷�����ָ��ͨѶ�˿� (Comm Port)��";
	if(error==2483)
		return "UPS ��ʾ��·�жϻ��ز��㣬����û��������";
	if(error==2484)
		return "UPS �����޷�ִ��ϵͳ�ػ��Ĳ�����";
	if(error==2500)
		return "����ĳ��򷵻�һ�� MS-DOS ������:";
	if(error==2501)
		return "����ĳ�����Ҫ������ڴ�:";
	if(error==2502)
		return "�����������˲�֧�ֵ� MS-DOS ����:";
	if(error==2503)
		return "����վ�޷�������";
	if(error==2504)
		return "������ļ����𻵡�";
	if(error==2505)
		return "�����鶨���ļ���û��ָ����������";
	if(error==2506)
		return "NetBIOS ���ش���: NCB �� SMB ����ת����";
	if(error==2507)
		return "���� I/O ����";
	if(error==2508)
		return "�޷��滻ӳ�������";
	if(error==2509)
		return "��Խ����������Χ��ӳ�����̫�ࡣ";
	if(error==2510)
		return "���Ǵ��� /S ��ʽ���� MS-DOS���̲�����ӳ��";
	if(error==2511)
		return "�Ժ���Զ������������";
	if(error==2512)
		return "�޷�����Զ��������������";
	if(error==2513)
		return "�޷����ӵ�Զ��������������";
	if(error==2514)
		return "�޷���Զ�������������ϵ�ӳ���ļ���";
	if(error==2515)
		return "�������ӵ�Զ������������...";
	if(error==2516)
		return "�������ӵ�Զ������������...";
	if(error==2517)
		return "Զ�����������Ѿ�ֹͣ����������¼�ļ������������ԭ��";
	if(error==2518)
		return "Զ������ʧ�ܣ����������־�ļ������������ԭ��";
	if(error==2519)
		return "������ڶ���Զ������ (Remoteboot) ��Դ���ӡ�";
	if(error==2550)
		return "����������ó� MaintainServerList=No��";
	if(error==2610)
		return "��Ϊû���������������һ�������������޷���������";
	if(error==2611)
		return "��Ϊע����е�������Ϣ����ȷ�������޷���������";
	if(error==2612)
		return "�޷���������ԭ�����������ݿ��Ҳ������𻵡�";
	if(error==2613)
		return "��Ϊ�Ҳ��� RPLFILES �������Դ�������޷���������";
	if(error==2614)
		return "��Ϊ�Ҳ��� RPLUSER �飬�����޷���������";
	if(error==2615)
		return "�޷�ö�ٷ����¼��";
	if(error==2616)
		return "����վ��¼��Ϣ���𻵡�";
	if(error==2617)
		return "����վ��¼�Ҳ�����";
	if(error==2618)
		return "�����Ĺ���վ����ʹ�ô˹���վ����";
	if(error==2619)
		return "�����ļ���¼���𻵡�";
	if(error==2620)
		return "�����ļ���¼�Ҳ�����";
	if(error==2621)
		return "�����������ļ�����ʹ�ô����ơ�";
	if(error==2622)
		return "�кܶ๤��վ����ʹ�ô������ļ���";
	if(error==2623)
		return "���ü�¼���𻵡�";
	if(error==2624)
		return "���ü�¼�Ҳ�����";
	if(error==2625)
		return "������ʶ���¼���𻵡�";
	if(error==2626)
		return "�ڲ��������";
	if(error==2627)
		return "��Ӧ��ʶ���¼���𻵡�";
	if(error==2628)
		return "�������¼���𻵡�";
	if(error==2629)
		return "�Ҳ����˹���վ���û��ʻ���¼��";
	if(error==2630)
		return "RPLUSER �������Ҳ�����";
	if(error==2631)
		return "�Ҳ����������¼��";
	if(error==2632)
		return "��ѡ�������ļ���˹���վ�����ݡ�";
	if(error==2633)
		return "�����Ĺ���վ����ʹ����ѡ��������";
	if(error==2634)
		return "��Щ�����ļ�����ʹ�ô����á�";
	if(error==2635)
		return "����������վ�������ļ�����������ʹ�ô������顣";
	if(error==2636)
		return "�����޷�����Զ���������ݿ�ı��ݡ�";
	if(error==2637)
		return "�Ҳ�����������¼��";
	if(error==2638)
		return "�Ҳ�����Ӧ�̼�¼��";
	if(error==2639)
		return "������Ӧ�̼�¼����ʹ�ô˹�Ӧ�����ơ�";
	if(error==2640)
		return "��������������¼����ʹ���������ƻ�Ӧ��ʶ���¼��";
	if(error==2641)
		return "��������������ʹ�ô��������ơ�";
	if(error==2660)
		return "�� Dfs ������ά�����ڲ����ݿ�����";
	if(error==2661)
		return "�ڲ����ݿ��е�һ����¼�� ��";
	if(error==2662)
		return "������·�����·����ƥ��";
	if(error==2663)
		return "���������Ѵ���";
	if(error==2664)
		return "ָ���ķ������������� Dfs �й���";
	if(error==2665)
		return "����ʾ�ķ���������֧������ʾ�� Dfs ��";
	if(error==2666)
		return "�˲����ڷ�Ҷ������Ч��";
	if(error==2667)
		return "�˲�����Ҷ������Ч��";
	if(error==2668)
		return "�˲�������ȷ����Ϊ�þ���ڶ��������";
	if(error==2669)
		return "�޷��������ӵ�";
	if(error==2670)
		return "�÷��������� Dfs ��ʶ���";
	if(error==2671)
		return "ָ����������Ŀ��·����Ч��";
	if(error==2672)
		return "ָ�� Dfs ������";
	if(error==2673)
		return "ָ���ķ�������Ϊ�˾����";
	if(error==2674)
		return "��⵽ Dfs ���еĻ�·";
	if(error==2675)
		return "�ڻ��ڷ������� Dfs �ϲ�֧�ָò���";
	if(error==2676)
		return "������Ѿ��ܸ�ָ������������֧��";
	if(error==2677)
		return "�޷�ɾ����������һ������������֧��";
	if(error==2678)
		return "Inter-Dfs ��֧�ָò���";
	if(error==2679)
		return "Dfs ������ڲ�״̬�Ѿ���ò�һ��";
	if(error==2680)
		return "Dfs �����Ѿ���װ��ָ���ķ�������";
	if(error==2681)
		return "��Э���� Dfs ������һ����";
	if(error==2682)
		return "�޷�ɾ�� Dfs ��Ŀ¼�� - ����Ҫ��ж�� Dfs";
	if(error==2683)
		return "�ù������Ŀ¼��Ŀ¼�Ѿ�������һ�� Dfs ��";
	if(error==2690)
		return "Dfs �ڲ�����";
	if(error==2691)
		return "��̨�����Ѿ������� ��";
	if(error==2692)
		return "�������Ŀǰδ������";
	if(error==2693)
		return "��̨��������������������޷��������˳���";
	if(error==2694)
		return "Ŀ�����������֧���� OU �д����Ļ����ʻ���";
	if(error==2695)
		return "ָ���Ĺ���������Ч";
	if(error==2696)
		return "ָ���ļ�����������������ʹ�õ�Ĭ�����Բ����ݡ�";
	if(error==2697)
		return "�Ҳ���ָ���ļ�����ʻ���";
	if(error==2999)
		return "���� NERR ��Χ�ڵ����һ������";
	if(error==3000)
		return "ָ����δ֪�Ĵ�ӡ��������";
	if(error==3001)
		return "ָ���Ĵ�ӡ����������ǰ����ʹ�á�";
	if(error==3002)
		return "�Ҳ��������ļ���";
	if(error==3003)
		return "δ���� StartDocPrinter ���á�";
	if(error==3004)
		return "δ���� AddJob ���á�";
	if(error==3005)
		return "ָ���Ĵ�ӡ�������Ѿ���װ��";
	if(error==3006)
		return "ָ���Ĵ�ӡ�������Ѿ���װ��";
	if(error==3007)
		return "��ָ���Ĵ�ӡ���������߱���Ҫ��Ĺ��ܡ���";
	if(error==3008)
		return "��ָ���Ĵ�ӡ����������ʹ���С�";
	if(error==3009)
		return "����ӡ������ҵ�ųɶ���ʱ�˲��������ǲ�����ġ�";
	if(error==3010)
		return "����Ĳ����ɹ���ֱ����������ϵͳǰ���Ľ�������Ч��";
	if(error==3011)
		return "����Ĳ����ɹ���ֱ��������������ǰ���Ľ�������Ч��";
	if(error==3012)
		return "�Ҳ�����ӡ����";
	if(error==3023)
		return "�û�ָ���Ĺػ������ļ����������������⡣���� UPS �����Ѿ�������";
	if(error==3029)
		return "��Ϊ�û��ʻ����ݿ� (NET.ACC) �Ҳ������𻵣�����Ҳû�п��õı������ݿ⣬���Բ����������ذ�ȫ���ơ�ϵͳ����ȫ��";
	if(error==3037)
		return "@I *��¼Сʱ��";
	if(error==3039)
		return "�Ѿ�����һ��Ŀ¼���ļ��ĸ������Ƶ����ơ�";
	if(error==3040)
		return "�Ѿ������������Ƶ�Ŀ¼��������ơ�";
	if(error==3046)
		return "�޷���¼���û���ǰ�Ѿ���¼��ͬʱ���� TRYUSER����Ϊ NO��";
	if(error==3052)
		return "�����л������ļ���û���ṩ��Ҫ�Ĳ�����";
	if(error==3054)
		return "�޷�������Դ������";
	if(error==3055)
		return "ϵͳ���������⡣";
	if(error==3056)
		return "ϵͳ����";
	if(error==3057)
		return "�����ڲ�һ���ԵĴ���";
	if(error==3058)
		return "�����ļ��������е�ѡ���ȷ��";
	if(error==3059)
		return "�����ļ��������еĲ����ظ���";
	if(error==3060)
		return "����û����Ӧ���ƣ�DosKillProc �����Ѿ�ֹͣ����";
	if(error==3061)
		return "���з������ʱ����";
	if(error==3062)
		return "�޷������μ�����";
	if(error==3064)
		return "�ļ������⡣";
	if(error==3070)
		return "�ڴ�";
	if(error==3071)
		return "���̿ռ�";
	if(error==3072)
		return "�߳�";
	if(error==3073)
		return "����";
	if(error==3074)
		return "��ȫ��ʧ�ܡ�";
	if(error==3075)
		return "LAN Manager ��Ŀ¼����ȷ���Ҳ�����";
	if(error==3076)
		return "δ��װ���������";
	if(error==3077)
		return "������δ������";
	if(error==3078)
		return "�������޷������û��ʻ����ݿ� (NET.ACC)��";
	if(error==3079)
		return "LANMAN ���а�װ���ļ������ݡ�";
	if(error==3080)
		return "LANMAN/LOGS Ŀ¼��Ч��";
	if(error==3081)
		return "ָ�������޷�ʹ�á�";
	if(error==3082)
		return "��һ����������˼������������Ϣ����ʹ�á�";
	if(error==3083)
		return "������������ʧ�ܡ�";
	if(error==3084)
		return "�û��ʻ����ݿ�û����ȷ���á�";
	if(error==3085)
		return "������û�������û�����ȫ���ܡ�";
	if(error==3087)
		return "����վ���ò���ȷ��";
	if(error==3088)
		return "�鿴���Ĵ�����־�ļ����˽���ϸ��Ϣ��";
	if(error==3089)
		return "�޷�д����ļ���";
	if(error==3090)
		return "ADDPAK �ļ��𻵡���ɾ�� LANMAN/NETPROG/ADDPAK.SER������Ӧ�����е� ADDPAK��";
	if(error==3091)
		return "��Ϊû������ CACHE.EXE�������޷����� LM386 ��������";
	if(error==3092)
		return "��ȫ���ݿ����Ҳ�����̨��������ʻ���";
	if(error==3093)
		return "��̨��������� SERVERS ��ĳ�Ա��";
	if(error==3094)
		return "SERVERS ��û���ڱ��ذ�ȫ���ݿ��С�";
	if(error==3095)
		return "�� Windows NT �����������Ϊĳ����ĳ�Ա����������ĳ�Ա�����������²���Ҫ���� Netlogon ����";
	if(error==3096)
		return "�Ҳ�������� Windows NT ���������";
	if(error==3098)
		return "�����޷������������������֤��";
	if(error==3099)
		return "��ȫ���ݿ��ļ��������ڻ���������⡣";
	if(error==3100)
		return "��Ϊ����������������޷�ִ�в�����";
	if(error==3102)
		return "��������޷���������������ƿ� (NCB) �ĶΡ����������������ݡ�";
	if(error==3103)
		return "��������޷����������ƿ� (NCB) �εĳ������������������������ݡ�";
	if(error==3106)
		return "�յ������������ƿ� (NCB)��NCB ����������ݡ�";
	if(error==3107)
		return "����û��������";
	if(error==3108)
		return "NETWKSTA.SYS �� DosDevIoctl �� DosFsCtl ����ʧ�ܡ���ʾ������Ϊ���¸�ʽ:DWORD ֵ������� Ioctl �� FsCtl �� CS:IP WORD ������� WORD Ioctl �� FsCtl ��";
	if(error==3111)
		return "��������� NetBIOS ���󡣴��������������ݡ�";
	if(error==3112)
		return "�յ��ķ�������Ϣ�� (SMB) ��Ч��SMB ����������ݡ�";
	if(error==3114)
		return "��Ϊ��������������Դ�����־�ļ��в��ݵ���Ŀ��ʧ��";
	if(error==3120)
		return "�������绺����������Դ�����ĳ�ʼ�����������ô�С�������Ҫ���ڴ�̫�ࡣ";
	if(error==3121)
		return "�������޷������ڴ�εĴ�С��";
	if(error==3124)
		return "����������ʧ�ܡ����� chdev��������ͬʱΪ�����ͬʱ��Ϊ�㡣";
	if(error==3129)
		return "�������޷����� AT �ƻ��ļ����ļ��𻵡�";
	if(error==3130)
		return "���������� NetMakeLMFileName ʱ�������������������ݡ�";
	if(error==3132)
		return "�޷��������������������������齻�����̵Ŀ��ÿռ䣬Ȼ����������ϵͳ��������������";
	if(error==3140)
		return "��Ϊ�����������������ƿ� (NCB) ��������ֹͣ�������һ������ NCB ��ԭʼ������ʽ���֡�";
	if(error==3141)
		return "��Ϊ��Ϣ��������������ݶα���ס��������Ϣ�������Ѿ�ֹͣ���С�";
	if(error==3151)
		return "��Ϊ VIO ���ó��������޷�������ʾ��Ϣ�����������������ݡ�";
	if(error==3152)
		return "�յ��ķ�������Ϣ�� (SMB) ��Ч��SMB ����������ݡ�";
	if(error==3160)
		return "����վ��Ϣ�δ��� 64K����С����(�� DWORD ֵ�ĸ�ʽ):";
	if(error==3161)
		return "����վ�޷�ȡ�ü���������ƺ��롣";
	if(error==3162)
		return "����վ�޷���ʼ�� Async NetBIOS �̡߳����������������ݡ�";
	if(error==3163)
		return "����վ�޷�����ǰ��Ĺ���Ρ����������������ݡ�";
	if(error==3164)
		return "����վ������������";
	if(error==3165)
		return "�յ�����Ͳ��������Ϣ�� (SMB) �����⣬SMB ����������ݡ�";
	if(error==3166)
		return "����վ�����û��ʻ����ݿ�ʱ�������������������ݡ�";
	if(error==3167)
		return "����վ��Ӧ SSI ������֤����ʱ���������뼰���������������ݡ�";
	if(error==3174)
		return "�������޷���ȡ AT �ƻ��ļ���";
	if(error==3175)
		return "���������ִ���� AT �ƻ���¼��";
	if(error==3176)
		return "�������Ҳ��� AT �ƻ��ļ������Դ���һ���ƻ��ļ���";
	if(error==3185)
		return "��Ϊ�û��ʻ����ݿ� (NET.ACC) �Ҳ������𻵣�����Ҳû�п��õı������ݿ⣬���Բ����������ذ�ȫ���ơ�ϵͳ����ȫ��";
	if(error==3204)
		return "�������޷������̡߳�CONFIG.SYS �е� THREADS ��������Ӵ�";
	if(error==3213)
		return "�Ѿ�����һ��Ŀ¼���ļ��ĸ������Ƶ����ơ�";
	if(error==3214)
		return "�Ѿ������������Ƶ�Ŀ¼��������ơ�";
	if(error==3215)
		return "��Ͳ���յ�����Ϣ�޷�ʶ��";
	if(error==3217)
		return "�޷���¼���û���ǰ�Ѿ���¼��ͬʱ���� TRYUSER����Ϊ NO��";
	if(error==3230)
		return "��⵽�������ĵ�Դ�жϡ�";
	if(error==3231)
		return "UPS �����Ѿ��ص���������";
	if(error==3232)
		return "UPS ����û�����ִ���û�ָ���Ĺػ������ļ���";
	if(error==3233)
		return "�޷��� UPS �������򡣴��������������ݡ�";
	if(error==3234)
		return "��Դ�Ѿ��ָ���";
	if(error==3235)
		return "�û�ָ���Ĺػ������ļ������⡣";
	if(error==3256)
		return "�������Ķ�̬���ӿⷢ���޷��޸��Ĵ���";
	if(error==3257)
		return "ϵͳ��������Ĵ����롣���������������ݡ�";
	if(error==3258)
		return "�ݴ������־�ļ� - LANROOT/LOGS/FT.LOG���� 64K��";
	if(error==3259)
		return "�ݴ������־�ļ� - LANROOT/LOGS/FT.LOG���ڱ���ʱ�������ø��½���λ�����ʾ�ϴ�ʹ�ô�����־ʱ��ϵͳ������";
	return "[GetLastError][ERROR]Return value is not in the lib.";
}

#endif
//https://blog.csdn.net/gooddaddy/article/details/4030468
