package com.emp.pay.bb;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class CompanyEmployeePayrollTest {
	
	/* A few notes before we begin.
	 * 
	 * I combined the respective setter and getter test cases into one 
	 * by using the setter method to place a predetermined value into 
	 * the variable and then using the getter method to retrieve it and 
	 * compare it directly with that predetermined value.
	 * 
	 * I will be commenting as I go along to clarify why I am doing some 
	 * of the stuff I am doing */
	
	//Created instances of all the classes
	Employee employee = new Employee();
	HourlyEmployee hourEmp = new HourlyEmployee();
	PieceWorkerEmployee phEmp = new PieceWorkerEmployee();
	SalariedEmployee sEmp = new SalariedEmployee();
	CommissionEmployee cEmp = new CommissionEmployee();
	BaseSalariedCommissionEmployee bscEmp = new BaseSalariedCommissionEmployee();

	@Test
	public void NameTest() {
		employee.setName("Joe");
		assertEquals(employee.getName(), "Joe");	
	}
	
	@Test
	public void AddressTest() {
		employee.setAddress("TestAddress");
		assertEquals(employee.getAddress(), "TestAddress");
	}
	
	@Test
	public void SINTest() {
		employee.setSIN("222222222");
		assertEquals(employee.getSIN(), "222222222");
	}
	
	@Test
	public void wageTest() {
		hourEmp.setWage(14.00);
		assertEquals(hourEmp.getWage(), 14.00);
	}
	
	@Test
	public void hoursTest() {
		hourEmp.setHours(25.5);
		assertEquals(hourEmp.getHours(), 25.5);
	}
	
	@Test
	public void hourlyEmployeeEarningsTest1() {
		//we want to calculate based on that logic
		//we will set our own values for each and determine the value ourselves 
		//and then compare with what the algorithm outputs
		//Note: The setter methods of proven to work if previous tests pass
		
		//1. <= 40
		//We reset the value to avoid error
		hourEmp.setHours(25.5);
		hourEmp.setWage(14.00);
		assertEquals(hourEmp.hourlyEmployeeEarnings(), 357);
	}
	
	@Test
	public void hourlyEmployeeEarningsTest2() {
		//we want to calculate based on that logic
		//we will set our own values for each and determine the value ourselves 
		//and then compare with what the algorithm outputs
		//Note: The setter methods of proven to work if previous tests pass
		
		//2. > 40
		//We reset the value to avoid error
		hourEmp.setHours(50);
		hourEmp.setWage(14.00);

		assertEquals(hourEmp.hourlyEmployeeEarnings(), 770);
	}
	
	@Test
	public void WagePerPiecesTest() {
		phEmp.setWagePerPieces(5.00);
		assertEquals(phEmp.getWagePerPieces(), 5.00);
	}
	
	@Test
	public void NumberOfPiecesOfMerchandiseTest() {
		phEmp.setNumberOfPiecesOfMerchandise(50);
		assertEquals(phEmp.getNumberOfPiecesOfMerchandise(), 50);
	}
	
	@Test
	public void pieceWorkerEmployeeEarningsTest() {
		//we want to calculate based on that logic
		//we will set our own values for each and determine the value ourselves 
		//and then compare with what the algorithm outputs
		//Note: The setter methods are proven to work if previous tests pass
		
		//We reset the value to avoid error
		phEmp.setWagePerPieces(5.00);
		phEmp.setNumberOfPiecesOfMerchandise(50);
		assertEquals(phEmp.pieceWorkerEmployeeEarnings(), 252.5);
	}
	
	@Test
	public void WeeklySalaryTest() {
		sEmp.setWeeklySalary(1200.00);
		assertEquals(sEmp.getWeeklySalary(), 1200.00);
	}
	
	@Test
	public void salariedEmployeeEarningsTest() {
		sEmp.setWeeklySalary(1200.00);
		assertEquals(sEmp.salariedEmployeeEarnings(), 1200.00);
	}
	
	@Test
	public void CommissionRateTest() {
		cEmp.setCommissionRate(20.00);
		assertEquals(cEmp.getCommissionRate(), 20.00);
	}
	
	@Test
	public void GrossSalesTest() {
		cEmp.setGrossSales(300.20);
		assertEquals(cEmp.getGrossSales(), 300.20);
	}
	
	@Test
	public void CommissionEmployeeEarningsTest() {
		//we want to calculate based on that logic
		//we will set our own values for each and determine the value ourselves 
		//and then compare with what the algorithm outputs
		//Note: The setter methods are proven to work if previous tests pass
		
		//We reset the value to avoid error
		cEmp.setCommissionRate(20.00);
		cEmp.setGrossSales(300.20);
		assertEquals(cEmp.commissionEmployeeEarnings(), 6004);
	}
	
	
	@Test
	public void BaseSalaryTest() {
		bscEmp.setBaseSalary(14.00);
		assertEquals(bscEmp.getBaseSalary(), 14.00);
	}
	
	@Test
	public void baseSalariedCommissionEmployeeEarningsTest() {
		//we want to calculate based on that logic
		//we will set our own values for each and determine the value ourselves 
		//and then compare with what the algorithm outputs
		//Note: The setter methods are proven to work if previous tests pass
		
		//We reset the value to avoid error
		bscEmp.setBaseSalary(14.00);
		bscEmp.setCommissionRate(20.00);
		bscEmp.setGrossSales(300.20);
		assertEquals(bscEmp.baseSalariedCommissionEmployeeEarnings(), 6018);
	}
	
	
		
	
}
