package com.labs.entities;

public class Values {

	private float firstValue;		//входные значения
	private float secondValue;
	private float thirdValue;
	private float maxValue;			//результат
	
	public float getFirstValue() {return firstValue;}				//геттеры
	public float getSecondValue() {return secondValue;}
	public float getThirdValue() {return thirdValue;}
	public float getMaxValue() {return maxValue;}
	
	public void setFirstValue(float input) {firstValue = input;}	//сеттеры
	public void setSecondValue(float input) {secondValue = input;}
	public void setThirdValue(float input) {thirdValue = input;}
	public void setMaxValue(float input) {maxValue = input;}

	public Values() {		//конструктор по умолчанию
		this.firstValue = 0;
		this.secondValue = 0;
		this.thirdValue = 0;
	}
	public Values(float first, float second, float third) {	//конструктор
		this.firstValue = first;
		this.secondValue = second;
		this.thirdValue = third;
	}
}
