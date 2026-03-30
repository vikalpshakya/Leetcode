func checkStrings(s1 string, s2 string) bool {
    var n = len(s1)
    mp1 := make(map[byte]int)
    mp2 := make(map[byte]int)

    for i := 0; i < n; i++{
        if i%2 == 0 {
            mp1[s1[i]]++
            mp1[s2[i]]--
        } else {
            mp2[s1[i]]--
            mp2[s2[i]]++
        }

        deleteIfEmpty(mp1,mp2,s1[i],s2[i])       
    }

    return len(mp1) == 0 && len(mp2) == 0
}

func deleteIfEmpty(m1 map[byte]int , m2 map[byte]int, ch1 byte , ch2 byte) {
    if(m1[ch1] == 0) {
        delete(m1,ch1)
    }
    if(m1[ch2] == 0) {
        delete(m1,ch2)
    }
    if(m2[ch1] == 0) {
        delete(m2,ch1)
    }
    if(m2[ch2] == 0) {
        delete(m2,ch2)
    }
}