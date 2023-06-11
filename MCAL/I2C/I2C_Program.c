/*
 * I2C_Program.c
 *
 *  Created on: Apr 10, 2023
 *      Author: Muham
 */

#include"Bit_Math.h"
#include"std_types.h"
#include"I2C_Interface.h"
#include"I2C_Private.h"
#include"I2c_Register.h"
#include"I2c_Config.h"

void I2C_VidInitMaster(u8 Copu_u8SlaveAddress)
{
	// set the clock Freq 400kbps
	// set TWBR to 2
	TWBR = 2;
	// clear the 2 bits of TWPS
	Clr_Bit(TWSR,TWSR_TWPS0);
	Clr_Bit(TWSR,TWSR_TWPS1);

	//intialize node address
	if(Copu_u8SlaveAddress !=0)
	{
		TWAR=Copu_u8SlaveAddress<<1	;
	}

	// TWI Enable
	Set_Bit(TWCR,TWCR_TWEN);
}

void I2C_VidInitSlave(u8 Copu_u8SlaveAddress)
{
	//intialize node address
	TWAR=Copu_u8SlaveAddress<<1	;

	// TWI Enable
	Set_Bit(TWCR,TWCR_TWEN);
}

I2C_ERROR_STATUS I2C_StartCondition(void)
{
	I2C_ERROR_STATUS Local_ErrStatus=NOK;

	//send start conditon on bus
	Set_Bit(TWCR,TWCR_TWSTA);
	// Clear interrupt flag to start the previous operation
	Set_Bit(TWCR,TWCR_TWINT);

	//wait until the interrupt flag is raised again and previous operation is complete
	while((Get_Bit(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != Start_Ack)
	{
		Local_ErrStatus = StartConditionErr;
	}
	else
	{
		//Do noithing
	}

	return Local_ErrStatus;
}
I2C_ERROR_STATUS I2C_RepeatedStart(void)
{
	I2C_ERROR_STATUS Local_ErrStatus=NOK;

	//send start conditon on bus
	Set_Bit(TWCR,TWCR_TWSTA);
	// Clear interrupt flag to start the previous operation
	Set_Bit(TWCR,TWCR_TWINT);

	//wait until the interrupt flag is raised again and previous operation is complete
	while((Get_Bit(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != Rep_Start_Ack)
	{
		Local_ErrStatus = RepeatedStartConditionErr;
	}
	else
	{
		//Do noithing
	}

	return Local_ErrStatus;

}
I2C_ERROR_STATUS I2C_Master_Send_Slave_Address_With_Write(u8 Address)
{
	I2C_ERROR_STATUS Local_ErrStatus=NOK;

	// clear start condition bit
	Clr_Bit(TWCR,TWCR_TWSTA);

	// set slave address in 7 MSB in data register
	TWDR=Address<<1;
	Clr_Bit(TWDR,0);	// for write request

	// Clear interrupt flag to start the previous operation
	Set_Bit(TWCR,TWCR_TWINT);

	//wait until the interrupt flag is raised again and previous operation is complete
	while((Get_Bit(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != Slave_Add_Wr_Ack)
	{
		Local_ErrStatus = SlaveAddWithWriteErr;
	}
	else
	{
		//Do noithing
	}

	return Local_ErrStatus;


}
I2C_ERROR_STATUS I2C_Master_Send_Slave_Address_With_Read(u8 Address)
{
	I2C_ERROR_STATUS Local_ErrStatus=NOK;

	// clear start condition bit
	Clr_Bit(TWCR,TWCR_TWSTA);

	// set slave address in 7 MSB in data register
	TWDR=Address<<1;
	Set_Bit(TWDR,0);	// for read request

	// Clear interrupt flag to start the previous operation
	Set_Bit(TWCR,TWCR_TWINT);

	//wait until the interrupt flag is raised again and previous operation is complete
	while((Get_Bit(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != Slave_Add_Rd_Ack)
	{
		Local_ErrStatus = SlaveAddWithReadErr;
	}
	else
	{
		//Do noithing
	}

	return Local_ErrStatus;

}
I2C_ERROR_STATUS I2C_Maste_Write_DataByte_To_Slave(u8 Data)
{
	I2C_ERROR_STATUS Local_ErrStatus=NOK;

	// write data byte
	TWDR= Data;

	// Clear interrupt flag to start the previous operation
	Set_Bit(TWCR,TWCR_TWINT);

	//wait until the interrupt flag is raised again and previous operation is complete
	while((Get_Bit(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != Master_Wr_Byte_Ack)
	{
		Local_ErrStatus = MAsterWriteByteErr;
	}
	else
	{
		//Do noithing
	}

	return Local_ErrStatus;


}
I2C_ERROR_STATUS I2C_Master_Read_DataByte_From_Slave (u8 * ptr)
{
	I2C_ERROR_STATUS Local_ErrStatus=NOK;

	// enable master generating ack bit after reciecving data
	Set_Bit(TWCR,TWCR_TWEA);

	// Clear interrupt flag to start the previous operation
	Set_Bit(TWCR,TWCR_TWINT);

	//wait until the interrupt flag is raised again and previous operation is complete
	while((Get_Bit(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != Master_Rd_Byte_Ack)
	{
		Local_ErrStatus = MAsterReadByteErr;
	}
	else
	{
		//Read the recieved data
		*ptr=TWDR;
	}

	return Local_ErrStatus;
}
void I2C_StopCondition(void)
{
	// generate stop condition
	Set_Bit(TWCR,TWCR_TWSTO);

	// Clear interrupt flag to start the previous operation
	Set_Bit(TWCR,TWCR_TWINT);


}
I2C_ERROR_STATUS I2C_Slave_Check_About_His_Addr_With_Write(void)
{
	I2C_ERROR_STATUS Local_ErrStatus=NOK;
	TWAR |=0X00;


	// enable Slave generating ack bit after Check address
	Set_Bit(TWCR,TWCR_TWEA);

	// Clear interrupt flag to start the previous operation
	Set_Bit(TWCR,TWCR_TWINT);

	//wait until the interrupt flag is raised again and previous operation is complete
	while((Get_Bit(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != Slave_Add_Rcvd_Wr_Req)
	{
		Local_ErrStatus = SlaveAddCheckWriteErr;
	}
	else
	{

	}

	return Local_ErrStatus;


}
I2C_ERROR_STATUS I2C_Slave_Check_About_His_Addr_With_Read(void)
{
	I2C_ERROR_STATUS Local_ErrStatus=NOK;
	TWAR |=0X01;


	// enable Slave generating ack bit after check address
	Set_Bit(TWCR,TWCR_TWEA);

	// Clear interrupt flag to start the previous operation
	Set_Bit(TWCR,TWCR_TWINT);

	//wait until the interrupt flag is raised again and previous operation is complete
	while((Get_Bit(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != Slave_Add_Rcvd_Rd_Req)
	{
		Local_ErrStatus = SlaveAddCheckReadErr;
	}
	else
	{

	}

	return Local_ErrStatus;

}
I2C_ERROR_STATUS I2C_Slave_Read_Byte_From_Master(u8 * ptr)
{
	I2C_ERROR_STATUS Local_ErrStatus=NOK;


	// enable Slave generating ack bit after reciecving data
	Set_Bit(TWCR,TWCR_TWEA);

	// Clear interrupt flag to start the previous operation
	Set_Bit(TWCR,TWCR_TWINT);

	//wait until the interrupt flag is raised again and previous operation is complete
	while((Get_Bit(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != Slave_Date_Rcvd)
	{
		Local_ErrStatus = SlaveDataRcvdErr;
	}
	else
	{
		*ptr = TWDR;
	}

	return Local_ErrStatus;

}
I2C_ERROR_STATUS I2C_Slave_Write_Byte_To_Master(u8 Data)
{
	I2C_ERROR_STATUS Local_ErrStatus=NOK;

	// write data byte
	TWDR= Data;

	// Clear interrupt flag to start the previous operation
	Set_Bit(TWCR,TWCR_TWINT);

	//wait until the interrupt flag is raised again and previous operation is complete
	while((Get_Bit(TWCR,TWCR_TWINT)) == 0);

	if((TWSR & 0xF8) != Slave_Byte_Trnsmit)
	{
		Local_ErrStatus = SlaveTrnsmitErr;
	}
	else
	{

	}

	return Local_ErrStatus;

}





