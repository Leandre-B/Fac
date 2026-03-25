public class TriGenerique {

	public static void tri(Object[] t, Object cmp){
		for(int i=0; i<t.length -1; ++i){
			for(int j=i+1; j<t.length; ++j){
				Compare compare = (Compare)cmp;
				if(compare.inf(t[i], t[j])){
					Object aux = t[i];
					t[i]=t[j];
					t[j]=aux;
				}
			}
		}
	}

}