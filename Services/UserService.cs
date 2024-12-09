using ANI.DTO;
using ANI.Models;
using ANI.Repository;
using AutoMapper;
using Microsoft.AspNetCore.Identity;

namespace ANI.Services;

public class UserService(IUserRepository userRepository, IMapper mapper, IPasswordHasher<User> passwordHasher) : IUserService
{
    private readonly IUserRepository _userRepository = userRepository;
    private readonly IMapper _mapper = mapper;
    private readonly IPasswordHasher<User> _passwordHasher = passwordHasher;

    public async Task<IEnumerable<UserSecDTO>> GetUsers()
    {
        return _mapper.Map<IEnumerable<UserSecDTO>>(await _userRepository.GetUsers()).Select(user =>
        {
            user.ProfilePictureUrl = PrependUrl(user.ProfilePictureUrl);
            return user;
        });
    }

    public async Task<UserResponseDTO> GetUser(string username)
    {
        UserResponseDTO userResponseDTO = _mapper.Map<UserResponseDTO>(await _userRepository.GetUser(username));
        userResponseDTO.ProfilePictureUrl = PrependUrl(userResponseDTO.ProfilePictureUrl);

        return userResponseDTO;
    }

    public async Task<UserResponseDTO> GetUser(Guid id)
    {
        UserResponseDTO userResponseDTO = _mapper.Map<UserResponseDTO>(await _userRepository.GetUser(id));

        userResponseDTO.ProfilePictureUrl = PrependUrl(userResponseDTO.ProfilePictureUrl);

        return userResponseDTO;
    }

    public async Task<UserResponseDTO> Authenticate(UserLoginDTO userLoginDTO)
    {
        try
        {
            User userFetch = await _userRepository.GetUser(userLoginDTO.Username);

            if (_passwordHasher.VerifyHashedPassword(userFetch, userFetch.Password, userLoginDTO.Password) == PasswordVerificationResult.Failed)
                throw new KeyNotFoundException("Invalid password.");

            UserResponseDTO userResponseDTO = _mapper.Map<UserResponseDTO>(userFetch);

            userResponseDTO.ProfilePictureUrl = PrependUrl(userFetch.ProfilePictureUrl);

            return _mapper.Map<UserResponseDTO>(userResponseDTO);
        }
        catch (KeyNotFoundException e)
        {
            throw new KeyNotFoundException(e.Message);
        }
    }

    public static string PrependUrl(string url)
    {
        return string.Concat("http://localhost:5088/", url);
    }

    public async Task<UserResponseDTO> GetUser(UserLoginDTO userLoginDTO)
    {
        try
        {
            User userFetch = await _userRepository.GetUser(userLoginDTO.Username);

            if (_passwordHasher.VerifyHashedPassword(userFetch, userFetch.Password, userLoginDTO.Password) == PasswordVerificationResult.Failed)
                throw new KeyNotFoundException("Invalid password.");

            UserResponseDTO userResponseDTO = _mapper.Map<UserResponseDTO>(userFetch);

            userResponseDTO.ProfilePictureUrl = PrependUrl(userFetch.ProfilePictureUrl);

            return userResponseDTO;
        }
        catch (KeyNotFoundException e)
        {
            throw new KeyNotFoundException(e.Message);
        }
    }

    public async Task<UserResponseDTO> CreateUser(UserCreateDTO user)
    {
        User userModel = _mapper.Map<User>(user);

        if (user.ProfilePictureUrl != null)
            userModel.ProfilePictureUrl = await SaveProfilePicture(user.ProfilePictureUrl);

        userModel.Password = _passwordHasher.HashPassword(userModel, userModel.Password);

        return _mapper.Map<UserResponseDTO>(await _userRepository.CreateUser(userModel));
    }

    private static async Task<string> SaveProfilePicture(IFormFile profilePicture)
    {
        string directoryPath = Path.Combine("Media", "Images", "Profiles");

        if (!Directory.Exists(directoryPath))
            Directory.CreateDirectory(directoryPath);

        string filePath = Path.Combine(directoryPath, $"{Guid.NewGuid()}_{profilePicture.FileName}");

        using (FileStream stream = new(filePath, FileMode.Create))
        {
            await profilePicture.CopyToAsync(stream);
        }

        return filePath;
    }

    public async Task<UserResponseDTO> UpdateUser(UserUpdateDTO newUser, Guid guid)
    {
        User user = await _userRepository.GetUser(guid);

        if (_passwordHasher.VerifyHashedPassword(user, user.Password, newUser.Password) == PasswordVerificationResult.Failed)
            throw new KeyNotFoundException("Invalid password.");

        if (newUser.ProfilePictureUrl != null)
            user.ProfilePictureUrl = await SaveProfilePicture(newUser.ProfilePictureUrl);

        user.Username = newUser.Username;
        if (!string.IsNullOrEmpty(newUser.NewPassword))
            user.Password = _passwordHasher.HashPassword(user, newUser.NewPassword);
        user.FirstName = newUser.FirstName;
        user.LastName = newUser.LastName;
        user.PhoneNumber = newUser.PhoneNumber;
        user.Address = newUser.Address;
        user.IsFarmer = newUser.IsFarmer;
        
        UserResponseDTO userResponseDTO = _mapper.Map<UserResponseDTO>(await _userRepository.UpdateUser(user));

        userResponseDTO.ProfilePictureUrl = PrependUrl(userResponseDTO.ProfilePictureUrl);

        return userResponseDTO;
    }

    public async Task<UserResponseDTO> DeleteUser(Guid id)
    {
        UserResponseDTO userResponseDTO = _mapper.Map<UserResponseDTO>(await _userRepository.DeleteUser(id));
        userResponseDTO.ProfilePictureUrl = PrependUrl(userResponseDTO.ProfilePictureUrl);
        return userResponseDTO;
    }
}