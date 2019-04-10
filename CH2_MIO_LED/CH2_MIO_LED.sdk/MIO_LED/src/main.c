#include "xgpiops.h"
#include "sleep.h"
int main()
{
	static XGpioPs psGpioInstancePtr;
	XGpioPs_Config* GpioConfigPtr;
	int iPinNumber= 7;			//LD9���ӵ���MIO7
	u32 uPinDirection = 0x1;	//1��ʾ�����0��ʾ����
	int xStatus;

	//--MIO�ĳ�ʼ��
    GpioConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
	if(GpioConfigPtr == NULL)
		return XST_FAILURE;

	xStatus = XGpioPs_CfgInitialize(&psGpioInstancePtr,GpioConfigPtr, GpioConfigPtr->BaseAddr);
	if(XST_SUCCESS != xStatus)
		print(" PS GPIO INIT FAILED \n\r");
	//--MIO�������������
     XGpioPs_SetDirectionPin(&psGpioInstancePtr, iPinNumber,uPinDirection);//����MIO�������
	 XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, iPinNumber,1);//����MIO�ĵ�7λ���
	 while(1)
	 {
		XGpioPs_WritePin(&psGpioInstancePtr, iPinNumber, 1);//����MIO�ĵ�7λ���1
		sleep(1);	//��ʱ
		XGpioPs_WritePin(&psGpioInstancePtr, iPinNumber, 0);//Ϩ��MIO�ĵ�7λ���0
		sleep(1);	//��ʱ
	 }

    return 0;
}
