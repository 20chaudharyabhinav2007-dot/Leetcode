class BusBooking {
    vector<bool>b;
    unordered_map<string,int>cost;
    int tot_time=0;
    int bookedcount = 0;
public:
    BusBooking(int n) {
        b.resize(4*n,false);
    }
    
    void toggle(string seat) {
        char t = seat[0];
        int row = stoi(seat.substr(1));
        int id = (row-1)*4;
        if(t == 'B'){
            id++;
        }else if(t == 'C'){
            id+=2;
        }else if(t == 'D'){
            id+=3;
        }
        if(b[id]){
            tot_time -= cost[seat];
            cost.erase(seat);
            b[id] = false;
            bookedcount--;
        }else{
            int time = 1;
        if(t == 'A' && b[id+1]){
            time = 3;
        }
        if(t == 'D' && b[id-1]){
            time = 3;
        }
        b[id] = true;
        cost[seat] = time;
        tot_time+=time;
        bookedcount++;
        }
    }
    
    int getTotalTime() {
        return tot_time;
    }
    
    int getMinTime() {
        return bookedcount;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */