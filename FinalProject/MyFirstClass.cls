//code for class
public class MyFirstClass{
	public integer i = 300;
	public integer j = 500;
	
	public integer add(){
		integer total = i+j;
		return total;
	}
	
	PUBLIC INTEGER WORK(INTEGER HOURS){
		INTEGER WAGE = HOURS * 10;
		RETURN WAGE;
	}
}


//code for execution
MyFirstClass obj = new MyFirstClass();
integer result = obj.add();
system.debug('Result = ' + result);

obj.i = 100;
obj.j = 200;
result = obj.add();
system.debug('Result = ' + result);

integer wage = obj.work(8);
system.debug('Wage = ' + wage);	