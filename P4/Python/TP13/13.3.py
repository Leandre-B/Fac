
def permute(s:str) -> list :

	if(len(s)==1):
		return list(s)
	else:
		result = []
		for c in s:
			s_wc = s.replace(c,'')
			print(f'{c} + permu {s_wc}')
			result=result+(permute(s_wc))
			#result+=(permute(s)).remove(c)
			print(f'{result}')
			for ch in result :
				result[i]=c+result[i]
		return result

def main() : 
	print(permute('abc'))


if __name__=='__main__' : 
	main()
