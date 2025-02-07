// Copyright (C) Kamaledin Ghiasi-Shirazi, Ferdowsi Univerity of Mashhad, Nov 28, 2024 (1403 Hijri Shamsi)
//
// 	Author:		Kamaledin Ghiasi-Shirazi 
//				Pourya Alvani
#pragma once

template <class T>
class KPivotsPartition :public IPartition<T>
{

public :
	virtual void partition (T* A, T* pivots, int* q, int p, int r, int k) {
		//write your code here.
		// مقدار دادن اولیه
		int qq=p;
		int kk=r+1;
		//q[-1] = -1;
		q[k] = 1000;
		for (int i= 0 ; i< k ; i++){
			q[i]=p;
		}
		for (int i= k ; i< k*2 ; i++){
			q[i]=r+1;
		}

		while (qq < kk){
			if (A[qq]< pivots[0]){
				//جا به جایی
				//ندارد 

				//درست کردن مقدار بقیه
				for (int j=0 ; j<k ; j++){
					q[j]++;
				}

				//تغییر مقدار خودش
				//q[k]++;

				//کنترل حرکت
				qq++;

			}else {
			for (int i =1 ; i<k ; i++){
				if (A[qq] == pivots[i]){// کامل است 
					//جا به جایی
					T temp = A[qq];
					A[qq] = A[q[i]];
					A[q[i]] = temp;
					for(int j=i ; j<k ; j++){
						if (q[i] < q[i+1]){
							T temp = A[qq];
							A[qq] = A[q[i+1]];
							A[q[i+1]] = temp;
						}
					}

					//درست کردن مقدار بقیه
					for (int j=i ; j< k ; j++){
						q[j]++;
					}

					//تغییر مقدار خودش
					//q[i]++;

					//کنترل حرکت
					qq++;

					break;

				}else if (A[qq] < pivots[i] ) {
					if (A[qq] > pivots[i-1]){
						//جا به جایی
						/*T temp = A[qq];
						A[qq] = A[q[i+k]];
						A[q[i+k]] = temp;*/

						//درست کردن مقدار بقیه
						for (int j=i+k-1 ; j>k-1 ; j--){
							q[j]--;
						}

						//تغییر مقدار خودش
						//q[k+i]--;

						//کنترل حرکت
						qq++;
						//kk--;

					break;

					}
				}
			}
			}		
		}
	}
};