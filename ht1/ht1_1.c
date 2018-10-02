int 
bitcount(STYPE value)
{
    UTYPE v = (UTYPE) value;
    int count = 0;
    while (v) {
        count += v & 1;
        v >>= 1;
    }
    return count;
}