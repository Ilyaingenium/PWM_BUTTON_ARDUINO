
#include <avr/io.h>                 // ���������� ��� avr, ����������� ��� ����������� ���������� ������ ��� ��������� �� 8, 16, 328 � �.�.
#define F_CPU 1000000UL            // ������ ������� ����������������, ��� ���� �������, ��� ������� ��������� �� � ������ ���������� �������
#include <util/delay.h>            // ���������� ��� ��������


void PWM_settings (void)
{
	TCCR1A |= (1<<COM1A1) | (0<<COM1A0); // ���������������  ����������������� ���- ������������ ����� ��������� �������� ����������
	    
    TCCR1A |= (1<<WGM10); // 10 ��� ���, ������ ������.
    TCCR1A |= (1<<WGM11); // 10 ��� ���, ������ ������.
    TCCR1B |= (1<<WGM12); // 10 ��� ���, ������ ������.
    TCCR1B &= ~(1<<WGM13); // 10 ��� ���, ������ ������.
	
    TCCR1B |= (1<<CS11); // ����� ������� �� �� 8
	TCCR1B &= ~((1<<CS10)|(1<<CS12)); // ����� ������� �� �� 8 = 125000
                                                     // timer counter control register (0 pin B-�������������, 8-������) ����� ������� �������� �� (8*1024)/1000000=0,008 ��� . ������� = 1024\0,008
                                                    // 1000000 / (8*1024)=122 ������� ������ ���
 }

int main(void) // ����� ������� ��������� ����������������. ����� ����������� ���� ���. ������� ��������  � ������  main ��������� ����� ����������������, ()- ����������� �������
{
    //������ ���
	DDRB = 0b00000010; // �.�. 10 ������ ��� ������������ ������ �  � oc1A, oc1b
	
	PWM_settings ();
	
    while (1) // ����� ������� ��������� ����������������. ����� ����������� �� �����
    {
        OCR1A = 211; // ���������� �������� ���������� 
        _delay_ms (500);
        OCR1A = 1023; // ���������� �������� ���������� 
        _delay_ms (500);
    }
}

