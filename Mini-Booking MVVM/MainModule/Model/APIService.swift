//
//  APIService.swift
//  Mini-Booking MVVM
//
//  Created by Korlan Omarova on 20.02.2021.
//

import Foundation
import Moya


enum APIService {
    case getHotelList
    case getHotelImage(imageName: String)
    case getHotelDetails(hotelID: Int)
}

extension APIService: TargetType {
    
    var baseURL: URL {
        return URL(string: "https://raw.githubusercontent.com/iMofas/ios-android-test/master/")!
    }
    
    var path: String {
        switch self {
        case .getHotelList:
            return "0777.json"
        case .getHotelImage(let imageName):
            return "\(imageName)"
        case .getHotelDetails(let hotelID):
            return "\(hotelID).json"
        }
    }
    
    var method: Moya.Method {
        switch self {
        case .getHotelList, .getHotelImage, .getHotelDetails:
            return .get
        }
    }
    
    var sampleData: Data {
        return Data()
    }
    
    var task: Task {
        switch self {
        case .getHotelList, .getHotelImage, .getHotelDetails:
            return .requestPlain
        }
    }
    
    var headers: [String : String]? {
        return nil
    }   
}
