class C {
	public: 
		// parameterized constructor
		C(char *s = "",int i = 0, double d = 1) {
			strcpy(dataMember1,s); 
			dataMember2 = i;
			dataMember3 = d;
		}	

		// class methods
		void memberFunction1() {
			cout << dataMember1 << ' ' << dataMember2 << ' ' << dataMember3 << endl;
		}
		
		void memberFunction2(int i,char *s ="unknown") {
			dataMember2 = i;
			cout << i << " received from " << s << endl; 
		}

	// data members
	protected:
		char dataMember1[20];
		int dataMember2;
		double dataMember3;
};


// instantiating many objects from class C
// C object1("object1",100,2000), object2("object2"), object3
