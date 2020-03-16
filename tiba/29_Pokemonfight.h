class Solution {
public:
    long long Pokemonfight(long long HP, long long ACK, long long HP2, long long ACK2) {
        if(ACK >= HP2) return -1;
        if(2 * ACK >= HP2){
            if(ACK2 >= HP) return 1;
            else return -1;
        }
        long cycle = (HP2 - 1) / ACK;
        long cycleattack = (cycle - 1) * ACK2;
        if((HP - ACK2) % cycleattack == 0) return (HP - ACK2) / cycleattack * cycle;
        else return (HP - ACK2) / cycleattack * cycle + 1 + ((HP - ACK2) % cycleattack - 1) / ACK2 + 1;
    }
};