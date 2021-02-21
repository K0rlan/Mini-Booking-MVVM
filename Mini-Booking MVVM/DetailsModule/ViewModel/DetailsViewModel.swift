//
//  DetailsViewModel.swift
//  Mini-Booking MVVM
//
//  Created by Korlan Omarova on 20.02.2021.
//

import Foundation
import Moya

protocol DetailsViewModelProtocol {
    var updateViewData: ((HotelDescription)->())? { get set }
    func startFetch(hotelID: Int)
}

protocol DetailsDetailsViewModelDelegateImage{
    func getImage()
}

final class DetailsViewModel: DetailsViewModelProtocol{
    var updateViewData: ((HotelDescription) -> ())?
    let provider = MoyaProvider<APIService>()
    
    init() {
        updateViewData?(.initial)
    }
    
    func startFetch(hotelID: Int) {
        updateViewData?(.loading)
        provider.request(.getHotelDetails(hotelID: hotelID)) { [weak self] (result) in
            switch result{
            case .success(let response):
                do {
                    let hotelResponse = try JSONDecoder().decode(HotelDescription.Data.self, from: response.data)
                    guard let image = hotelResponse.image else {
                        self?.updateViewData?(.success(hotelResponse))
                        return
                    }
                    self?.fetchImage(imageName: image, hotelResponse: hotelResponse)
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
    
    func fetchImage(imageName: String, hotelResponse: HotelDescription.Data) {
        provider.request(.getHotelImage(imageName: imageName)) { [weak self] (result) in
            print(result)
            switch result{
            case .success(let response):
                do {
                    HotelImage.sharedInstance.image = try response.mapImage()
                    self?.updateViewData?(.success(hotelResponse))
                    
                } catch let error {
                    print("There is no image: \(error)")
                    self?.updateViewData?(.success(hotelResponse))
                }
            case .failure(let error):
                let requestError = (error as NSError)
                print("Request Error message: \(error.localizedDescription), code: \(requestError.code)")
                self?.updateViewData?(.failure(error))
            }
        }
    }
    
}
