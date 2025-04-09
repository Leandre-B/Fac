
def permute(s:str) -> list :

	if(len(s)==1):
		return list(s)
	else:
		result = []
		for i in range(len(s)):
			c = s[i]
			reste = s[:i] + s[i+1:]
			sous_permu = permute(reste)
			for ch in sous_permu:
					result.append(c + ch)
	return result

def main() : 
	print(permute('abc'))


if __name__=='__main__' : 
	main()
