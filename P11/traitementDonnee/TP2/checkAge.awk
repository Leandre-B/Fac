BEGIN{
    FS=","
    bien_forme=0
}

#JJ/MM/AA
/([0-2][0-9]|[3][0-1])\/[0-1][0-9]\/[0-9][0-9]$/ {
    bien_forme=1

    s=substr($0, 1, length($0)-2)
    last_2_num=substr($0, length($0)-1, length($0))
    
    if(last_2_num < 10)
        s=s"20"last_2_num
    else
        s=s"19"last_2_num

    print s >> "bienFormate.txt" 
}


#JJ/MM/AAAA
/[0-3][0-9]\/[0-1][0-9]\/[0-9]{4}$/ {
    bien_forme=1
    print $0 >> "bienFormate.txt" 
}

/.+/{
    if(NR==1)
        print $0 > "bienFormate.txt" 
    else if(bien_forme==0)
        printf("Ligne %d '%s' mal formée : ignorée\n", NR, $0)
    bien_forme=0
}