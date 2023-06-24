        if(ft==0){
            if(a[fy+1][fx]=='*'||fy==9){ft=(ft+1)%4;continue;}
            else fy++;
        }
        if(ft==1){
            if(a[fy][fx+1]=='*'||fx==9){ft=(ft+1)%4;continue;}
            else fx++;
        }
        if(ft==2){
            if(a[fy-1][fx]=='*'||fy==0){ft=(ft+1)%4;continue;}
            else fy--;
        }
        if(ft==3){
            if(a[fy][fx-1]=='*'||fx==0){ft=(ft+1)%4;continue;}
            else fx--;
        }