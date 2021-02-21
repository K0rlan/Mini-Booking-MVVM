//
//  MainViewModel.swift
//  Mini-Booking MVVM
//
//  Created by Korlan Omarova on 20.02.2021.
//

import Foundation
import Moya

protocol MainViewModelProtocol {
    var updateViewData: ((HotelList)->())? { get set }
    func startFetch()
}

final class MainViewModel: MainViewModelProtocol{
    var updateViewData: ((HotelList) -> ())?
    let provider = MoyaProvider<APIService>()
    
    var hotels = [HotelList.Data]()
    
    init() {
        updateViewData?(.initial)
    }
    
    func startFetch() {
        updateViewData?(.loading)
        provider.request(.getHotelList) { [weak self] (result) in
            switch result{
            case .success(let response):
                do {
                    let hotelResponse = try JSONDecoder().decode([HotelList.Data].self, from: response.data)
                    self?.updateViewData?(.success(hotelResponse))
                    self?.hotels = hotelResponse
                } catch let error {
                    print("Error in parsing: \(error)")
                    self?.updateViewData?(.failure(error))
                }
            case .failure(let error):
                let requestError = (error as NSError)
                print("Request Error message: \(error.localizedDescription), code: \(requestError.code)")
                self?.updateViewData?(.failure(error))
            }
        }
    }
    
    func filterByLocation(){
        hotels.sort { $0.distance < $1.distance }
        self.updateViewData?(.success(hotels))
    }
    
    func filterByRooms(){
        hotels.sort {
            $0.suites_availability.components(separatedBy: ":").count > $1.suites_availability.components(separatedBy: ":").count
        }
        self.updateViewData?(.success(hotels))
    }
}
