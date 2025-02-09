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
		for (int i= 0 ; i< k ; i++){
			q[i]=p;
		}
		for (int i= k ; i< k*2 ; i++){
			q[i]=r+1;
		}

		while (qq <= q[k]-1){
			if (A[qq]< pivots[0]){//کامل است
				//جا به جایی
				//ندارد 

				//درست کردن مقدار بقیه
				//ندارد

				//تغییر مقدار خودش
				//ندارد

				//کنترل حرکت
				qq++;

			}else if (A[qq] > pivots[k-1]) {
				//جا به جایی
					T temp = A[qq];
					A[qq] = A[q[2*k-1]-1];
					A[q[2*k-1]-1] = temp;
						
					for(int j=k+k-1 ; j>k ; j--){
						if (q[j] > q[j-1]){
							T temp = A[qq];
							A[qq] = A[q[j-1]-1];
							A[q[j-1]-1] = temp;
						}
					}

					//درست کردن مقدار بقیه
					for (int j=k+k-1 ; j>k-1 ; j--){
						q[j]--;
					}

					//تغییر مقدار خودش
					//q[k+i]--; داخل حلقه بالا اضافه شد 

					//کنترل حرکت
					kk--;

			} else {
				for (int i =0 ; i<k ; i++){
					if (A[qq] == pivots[i]){
						//جا به جایی
						T temp = A[qq];
						A[qq] = A[q[i]];
						A[q[i]] = temp;
						for(int j=i ; j<k-1 ; j++){
							if (q[j] < q[j+1]){
								T temp = A[qq];
								A[qq] = A[q[j+1]];
								A[q[j+1]] = temp;
							}
						}

						//درست کردن مقدار بقیه
						for (int j=i ; j< k ; j++){
							q[j]++;
						}

						//تغییر مقدار خودش
						//q[i]++; داخل حلقه بالا اضافه شد 

						//کنترل حرکت
						qq++;

						break;

					}else if (A[qq] < pivots[i] ) {
						if (A[qq] > pivots[i-1]){
							//جا به جایی
							T temp = A[qq];
							A[qq] = A[q[i+k]-1];
							A[q[i+k]-1] = temp;

							for(int j=i+k ; j>k-1 ; j--){
								if (q[j+1] > q[j]){
									T temp = A[qq];
									A[qq] = A[q[j]-1];
									A[q[j]-1] = temp;
								}
							}

							//درست کردن مقدار بقیه
							for (int j=i+k-1 ; j>k-1 ; j--){
								q[j]--;
							}

							//تغییر مقدار خودش
							//q[k+i]--;داخل حلقه بالا اضافه شد

							//کنترل حرکت
							kk--;

							break;
						}
					}
				}
			}
		}
	}
};