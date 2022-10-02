char *elements_segmentation(char *str){
    //カンマでラベル，コマンド，オペランド，casファイルの中身に分ける
    int i=0,j=0,k=0;
    char *list[6];
    while(str[i]!='\0'){
        //カンマで区切る
        if(str[i]!=','){
            list[j][k] = str[i];
            k++;
        }
        else{
            //casファイルの中身ではないときは区切る
            if(j<5){
                list[j][k] = '\0';
                j++;
                k=0;
            }
            else{
                list[j][k] = str[i];
                k++;
            }
        }
        list[j][k] = '\0';
        i++;
    }
    return list;
}